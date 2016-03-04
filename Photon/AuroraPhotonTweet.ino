int ledpin = D7;
void setup()
{
// register the cloud function
Spark.function("tweet", twittermessage);
pinMode(ledpin, OUTPUT);
 
}
 
void loop()
{
delay(5000);
digitalWrite(ledpin, LOW);
delay(5000);
}
 
// this function automagically gets called upon a tweet mention
int twittermessage(String ignore)
{
digitalWrite(ledpin, HIGH);
return(0);
}
