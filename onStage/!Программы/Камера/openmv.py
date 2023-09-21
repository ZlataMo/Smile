import sensor, image,tf,math,time
from pyb import UART,LED

uart = UART(3, 9600)
led=LED(2)

sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.B128X128)

tag_families = 0
tag_families |= image.TAG16H5 # comment out to disable this family
tag_families |= image.TAG25H7 # comment out to disable this family
tag_families |= image.TAG25H9 # comment out to disable this family
tag_families |= image.TAG36H10 # comment out to disable this family
tag_families |= image.TAG36H11 # comment out to disable this family (default family)
tag_families |= image.ARTOOLKIT

while True:
    snap=sensor.snapshot().rotation_corr(x_rotation=180,y_rotation=180)
    tags=snap.find_apriltags(families=tag_families)
    if len(tags)!=0:
        t=tags[0]
        time.sleep(1)
        snap=sensor.snapshot().rotation_corr(x_rotation=180,y_rotation=180)
        img=snap.to_grayscale().copy(roi=(t.x()-20,t.y()-20,t.w()+45,t.w()+45),x_size=64)
        classification=tf.classify('model (2).tflite',img)[0][4]
        res=classification.index(max(classification))
        if res!=0:
            print(res-1)
