#include <dht_nonblocking.h>
#include <math.h>
#define BLUE 9
#define GREEN 10
#define RED 11

#define DHT_SENSOR_TYPE DHT_TYPE_11
static const int DHT_SENSOR_PIN = 2;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );

void setup( )
{
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);  
  Serial.begin( 9600);
}

// define variables
int redValue;
int greenValue;
int blueValue;

static bool measure_environment( float *temperature, float *humidity ){
  static unsigned long measurement_timestamp = millis( );
  /* Measure once every four seconds. */
  if ( millis( ) - measurement_timestamp >= 1000ul )
  {
    if ( dht_sensor.measure( temperature, humidity ) == true )
    {
      measurement_timestamp = millis( );
      return ( true );
    }
  }
  return ( false );
}

static void cycle_RGB_colors(){
  #define delayTime 10
  redValue = 255; // choose a value between 1 and 255 to change the color.
  greenValue = 0;
  blueValue = 0;
  for(int i = 0; i < 255; i += 1){
  redValue -= 1;
  greenValue += 1;
  analogWrite(RED, redValue);
  analogWrite(GREEN, greenValue);
  delay(delayTime);} 
  redValue = 0;
  greenValue = 255;
  blueValue = 0;  
  for(int i = 0; i < 255; i += 1){
  greenValue -= 1;
  blueValue += 1;
  analogWrite(GREEN, greenValue);
  analogWrite(BLUE, blueValue);
  delay(delayTime);}
  redValue = 0;
  greenValue = 0;
  blueValue = 255;  
  for(int i = 0; i < 255; i += 1){
  blueValue -= 1;
  redValue += 1;
  analogWrite(BLUE, blueValue);
  analogWrite(RED, redValue);
  delay(delayTime);
  }
}

static void set_RGB_color(float tempF, float humidity){
  redValue =  int(250-(5*(90 - tempF)));
  blueValue = int(5*(90 - tempF));
  // greenValue = ceil(2.5*humidity);
  // analogWrite(GREEN, greenValue);
  analogWrite(BLUE, blueValue);
  analogWrite(RED, redValue);
  Serial.print( "T = " );
  Serial.print( tempF, 1 );
  Serial.print( " deg. C, H = " );
  Serial.print( humidity, 1 );
  Serial.println( "%" );    
}

void loop( )
{
  float temperature;
  float humidity;
  if( measure_environment( &temperature, &humidity ) == true )
  {
    float tempF = (temperature * (9/5)) + 32.0;    
    
    set_RGB_color(tempF, humidity);
 }  
  
}
