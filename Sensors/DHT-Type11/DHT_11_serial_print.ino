#include <dht_nonblocking.h>
#include <math.h>

#define DHT_SENSOR_TYPE DHT_TYPE_11
static const int DHT_SENSOR_PIN = 2;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );

void setup( )
{ 
  Serial.begin( 9600);
}

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

void loop( )
{
  float temperature;
  float humidity;
  if( measure_environment( &temperature, &humidity ) == true )
  {
    float tempF = (temperature * (9/5)) + 32.0;    
    char reading[] = "Temp: %.2f Humidity: %.2f", tempF, humidity;
    Serial.print(reading);
 }  
  
}
