static void TaskHog(void *pvParameters)
{
    volatile uint32_t counter = 0U;

    TickType_t xLastWakeTime;

    (void)pvParameters;

    gpio_set_level(LED_HOG, 1);

    xLastWakeTime = xTaskGetTickCount();

    while (1)
    {
        counter++;

        if ((counter % 1000000U) == 0U)
        {
            printf(
                "[TaskHog] Running... counter=%lu\n",
                (unsigned long)counter
            );
        }
        
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(10));
    }
}
