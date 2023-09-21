void setup()
{
  Serial.begin(9600);
  Serial3.begin(9600);
}

void loop()
{
  Serial3.write(5);
}
