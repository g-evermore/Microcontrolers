This repository contains a collection of projects related to the use of microcontrollers and other hardware.
Within the Resources folder you will find a collection of reference code for implementing the various sensors
used throughout the projects listed, as well as some examples for hardware that have not found their way into
current projects





**WEATHER STATION:**


The Weather Station branch is an on-going project to create a center receiving repository of environmental data
that is generated by a collection of hardware recording devices. The devices connect to the weather station server
using TCP socket connections and send their current environmental readings. The weather station server will then
write those readings to a CSV file by recording the date, time, recording device number, and environmental reading.


As of the time of writing:


  Recording devices are a set of Raspberry Pi PICO W attached with DHT type 11 sensors. The PICO W was selected due
  the price and availability as well as the added wireless and bluetooth functionality. The DHT type 11 sensors were
  similarly chosen due to their price and easy availability.
 
  The choice of using TCP sockets for information gathering was chosen as an easy way to ensure proper time/date recordings
  across multiple devices and to provide immediate consolidation of readings into one master file.


  The station is designed to operate on a local network. There exists the possibility of expanding to public internet connection
  and/or reporting the information directly to an online repository or publically-accessible website.





