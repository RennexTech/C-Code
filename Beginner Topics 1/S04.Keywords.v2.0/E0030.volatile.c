/**
 * 
 * volatile is like putting a 'DO NOT CACHE! ALWAYS RE-READ!' sticky note on a variable. 
 * 
 * It tells the compiler, 'Listen, this variable's value might change at any time, 
 * 
 * even if my code isn't directly changing it. Don't try to be smart and remember its old value; 
 * 
 * always go back to memory and get the freshest value every single time you need it!' 
 * 
 * This is super important for things that interact directly with hardware or other parts of the system 
 * 
 * that your code doesn't fully control, like sensor readings or shared memory in multi-threaded programs.
 * 
 * Code Example (Conceptual - direct hardware interaction is complex):
 * 
 * Directly demonstrating volatile's effect is hard in a simple console program without actual hardware 
 * 
 * or multi-threading. However, we can simulate the concept of a value potentially changing outside the compiler's direct knowledge.

 */

#include <stdio.h>
#include <unistd.h> // For sleep

// In a real scenario, 'sensor_reading' might be updated by hardware or another thread
// The 'volatile' keyword tells the compiler NOT to optimize reads of this variable.
volatile int sensor_reading = 0;

void simulate_external_change(int new_value) {
    // This function simulates an external system changing the sensor_reading
    // (e.g., a hardware interrupt, or another thread)
    sensor_reading = new_value;
}

int main() {
    printf("--------------------------------------------\n");
    printf("31. volatile (Conceptual Demonstration)\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("'volatile' is like putting a **'DO NOT CACHE! ALWAYS RE-READ!'** sticky note on a variable... This is super important for things that interact directly with hardware or other parts of the system that your code doesn't fully control.\n");
    printf("--------------------------------------------\n");
    sleep(1);

    int local_copy_val;

    printf("Initial sensor reading: %d\n", sensor_reading); // Read 1

    // Compiler *might* optimize this: if 'sensor_reading' wasn't volatile,
    // it might assume its value hasn't changed because *this* code didn't change it.
    local_copy_val = sensor_reading; // Read 2

    printf("Local copy before external change: %d\n", local_copy_val);
    sleep(1);

    // Simulate an external event changing the sensor reading
    printf("Simulating external change to sensor reading...\n");
    simulate_external_change(50);
    sleep(1);

    // If 'sensor_reading' were NOT volatile, a smart compiler might use the old
    // cached value for 'sensor_reading' here, leading to stale data.
    // With 'volatile', it *must* re-read from memory.
    printf("Sensor reading AFTER external change: %d\n", sensor_reading); // Read 3 (guaranteed fresh)

    printf("Note: The real impact of 'volatile' is subtle and critical in specific low-level or multi-threaded contexts.\n");
    sleep(5);
    return 0;
}