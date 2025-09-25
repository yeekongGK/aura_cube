#ifndef BATTERY_MONITOR_H
#define BATTERY_MONITOR_H

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Initializes the battery monitor IC.
 *
 * This function handles the I2C initialization and configures the MAX17260
 * with the necessary values if a Power-On-Reset (POR) is detected.
 * It must be called once before any other functions in this module.
 */
void BatteryMonitor_Init(void);

/**
 * @brief Gets the raw Coulomb Counter (QH) value.
 *
 * The QH register represents the accumulated charge/discharge of the battery.
 * It is a 16-bit value that rolls over.
 *
 * @return The 16-bit value from the QH register.
 */
uint16_t BatteryMonitor_GetQH(void);

#endif // BATTERY_MONITOR_H
