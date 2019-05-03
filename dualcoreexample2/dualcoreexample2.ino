void setup() 
{
  Serial.begin(112500);
  delay(1000);
 
  xTaskCreatePinnedToCore(
                    taskOne,          /* Task function. */
                    "TaskOne",        /* String with name of task. */
                    10000,            /* Stack size in bytes. */
                    NULL,             /* Parameter passed as input of the task */
                    1,                /* Priority of the task. */
                    NULL,           /* Task handle. */
                    0);               /* Core to use */    
                     
  xTaskCreatePinnedToCore(
                    taskTwo,          /* Task function. */
                    "TaskTwo",        /* String with name of task. */
                    10000,            /* Stack size in bytes. */
                    NULL,             /* Parameter passed as input of the task */
                    1,                /* Priority of the task. */
                    NULL,           /* Task handle. */
                    1);               /* Core to use */            
 
}
 
void loop() {
  delay(1000);
}
 
void taskOne( void * parameter )
{
    for( int i = 0;i<10;i++ )
    {
        Serial.println("Hello from task 1");
        delay(1000);
    }
 
    Serial.println("Ending task 1");
    vTaskDelete( NULL );
}
 
void taskTwo( void * parameter)
{
    for( int i = 0;i<10;i++ ){
        Serial.println("Hello from task 2");
        delay(1000);
    }
    Serial.println("Ending task 2");
    vTaskDelete( NULL );
 
}
