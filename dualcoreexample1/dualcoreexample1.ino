

/*
 * This sketch moves the blink sketch from Core 1 in loop to Core 0
 */

TaskHandle_t Task1;

void ExampleTask1( void * parameter )
{
  for (;;) {
    Serial.print("This Task runs on Core: ");
    Serial.println(xPortGetCoreID());

    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);                       // wait for a second
  }
}

void setup() 
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);

  xTaskCreatePinnedToCore(
    ExampleTask1,            /* Task function. */
    "Task_1",                 /* name of task. */
    1000,                    /* Stack size of task */
    NULL,                     /* parameter of the task */
    1,                        /* priority of the task */
    &Task1,                   /* Task handle to keep track of created task */
    0);                       /* Core to use */
}

void loop() 
{
  delay(1000);
}
