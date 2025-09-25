#include "max17260.h"
#include "main.h"

// I2C Address for the MAX17260
#define MAX17260_I2C_ADDRESS 0x6C

// A subset of MAX17260 registers needed for init and getQH
typedef enum {
        STATUS = 0x00,
        V_ALRT_TH,
        T_ALRT_TH,
        S_ALRT_TH,
        AT_RATE,
        REP_CAP,
        REP_SOC,
        AGE,
        TEMP,
        V_CELL,
        CURRENT,
        AVG_CURRENT,
        Q_RESIDUAL,
        MIX_SOC,
        AV_SOC,
        MIX_CAP,
        FULL_CAP_REP,
        TTE,
        QR_TABLE_00,
        FULL_SOC_THR,
        R_CELL,
        AVG_TA = 0x16,
        CYCLES,
        DESIGN_CAP,
        AVG_V_CELL,
        MAX_MIN_TEMP,
        MAX_MIN_VOLT,
        MAX_MIN_CURR,
        CONFIG,
        I_CHG_TERM,
        AV_CAP,
        TTF,
        DEV_NAME,
        QR_TABLE_10,
        FULL_CAP_NOM,
        AIN = 0x27,
        LEARN_CFG,
        FILTER_CFG,
        RELAX_CFG,
        MISC_CFG,
        T_GAIN,
        T_OFF,
        C_GAIN,
        C_OFF,
        QR_TABLE_20 = 0x32,
        DIE_TEMP = 0x34,
        FULL_CAP,
        R_COMP0 = 0x38,
        TEMP_CO,
        V_EMPTY,
        F_STAT = 0x3D,
        TIMER,
        SHDN_TIMER,
        USER_MEM1,
        QR_TABLE_30 = 0x42,
        R_GAIN,
        DQ_ACC = 0x45,
        DP_ACC,
        CONVG_CFG = 0x49,
        VF_REM_CAP,
        QH = 0x4D,
		SOFT_WAKEUP = 0x60,
        STATUS_2 = 0xB0,
        POWER,
        ID_USER_MEM2,
        AVG_POWER,
        I_ALRT_TH,
        TTF_CFG,
        CV_MIX_CAP,
        CV_HALF_TIME,
        CG_TEMP_CO,
        CURVE,
        HIB_CFG,
        CONFIG2,
        V_RIPPLE,
        RIPPLE_CFG,
        TIMER_H,
        R_SENSE_USER_MEM3 = 0xD0,
        SC_OCV_LIM,
        V_GAIN,
        SOC_HOLD,
        MAX_PEAK_POWER,
        SUS_PEAK_POWER,
        PACK_RESISTANCE,
        SYS_RESISTANCE,
        MIN_SYS_VOLTAGE,
        MPP_CURRENT,
        SPP_CURRENT,
        MODEL_CFG,
        AT_Q_RESIDUAL,
        AT_TTE,
        AT_AV_SOC,
        AT_AV_CAP
}MAX17260_Reg_t;


//=============================================================================
// HARDWARE ABSTRACTION LAYER (HAL) - TO BE IMPLEMENTED BY USER
//=============================================================================
//
// You must provide the implementation for the following three static
// functions based on your specific microcontroller's I2C peripheral driver.
//
//=============================================================================

/**
 * @brief Initializes the I2C peripheral.
 * @note  This is a placeholder. Implement with your hardware's I2C init code.
 */
static void i2c_init(void) {
    // Example: i2c_master_init(I2C_NUM_0, ...);
}

/**
 * @brief Writes data to an I2C device.
 * @param dev_addr The 7-bit I2C device address.
 * @param reg_addr The register address to write to.
 * @param data A pointer to the data buffer to write.
 * @param len The number of bytes to write.
 * @return true on success, false on failure.
 */
static bool i2c_write(uint8_t dev_addr, uint8_t reg_addr, uint8_t* data, uint16_t len) {
    // This is a placeholder.
    // Implement this function using your platform's I2C write function.
    // It should handle the START, address, register, data, and STOP conditions.
    // For example: return HAL_I2C_Mem_Write(&hi2c1, dev_addr << 1, reg_addr, I2C_MEMADD_SIZE_8BIT, data, len, 100) == HAL_OK;
    return true; // Assume success for now
}

/**
 * @brief Reads data from an I2C device.
 * @param dev_addr The 7-bit I2C device address.
 * @param reg_addr The register address to read from.
 * @param data A pointer to the buffer to store the read data.
 * @param len The number of bytes to read.
 * @return true on success, false on failure.
 */
static bool i2c_read(uint8_t dev_addr, uint8_t reg_addr, uint8_t* data, uint16_t len) {
    // This is a placeholder.
    // Implement this function using your platform's I2C read function.
    // For example: return HAL_I2C_Mem_Read(&hi2c1, dev_addr << 1, reg_addr, I2C_MEMADD_SIZE_8BIT, data, len, 100) == HAL_OK;
    return true; // Assume success for now
}

/**
 * @brief Delays execution for a specified number of milliseconds.
 * @note This is a placeholder. Implement with your hardware's delay function.
 * @param ms Milliseconds to delay.
 */
static void delay_ms(uint32_t ms) {
    // Example: vTaskDelay(pdMS_TO_TICKS(ms)); or HAL_Delay(ms);
    volatile uint32_t i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 1000; j++) {
            __asm__("nop");
        }
    }
}


//=============================================================================
// MAX17260 DRIVER IMPLEMENTATION (INTERNAL)
//=============================================================================

/**
 * @brief Writes a single 16-bit value to a MAX17260 register.
 */
static bool MAX17260_Register_WriteSingle(uint8_t reg, uint16_t value) {
    uint8_t buffer[2];
    // Little-endian format
    buffer[0] = value & 0xFF;
    buffer[1] = (value >> 8) & 0xFF;
    return i2c_write(MAX17260_I2C_ADDRESS, reg, buffer, 2);
}

/**
 * @brief Reads a single 16-bit value from a MAX17260 register.
 */
static bool MAX17260_Register_ReadSingle(uint8_t reg, uint16_t* value) {
    uint8_t buffer[2];
    if (i2c_read(MAX17260_I2C_ADDRESS, reg, buffer, 2)) {
        // Little-endian format
        *value = (uint16_t)buffer[0] | ((uint16_t)buffer[1] << 8);
        return true;
    }
    *value = 0;
    return false;
}

/**
 * @brief Checks if the MAX17260 has experienced a Power-On-Reset.
 */
static bool IsPOR(void) {
    uint16_t status_val = 0;
    MAX17260_Register_ReadSingle(STATUS, &status_val);
    // POR bit is bit 1 of the STATUS register
    return (status_val & (1 << 1)) != 0;
}

/**
 * @brief Clears the Power-On-Reset flag in the STATUS register.
 */
static void ClearPOR(void) {
    uint16_t status_val = 0;
    MAX17260_Register_ReadSingle(STATUS, &status_val);
    // Write the value back, but with the POR bit cleared
    MAX17260_Register_WriteSingle(STATUS, status_val & ~(1 << 1));
}

/**
 * @brief Performs the initial configuration of the MAX17260.
 *
 * This sequence is extracted from the `BATTSENSOR_LWInit` function and is
 * critical for setting up the device's model and configuration.
 */
static void LWInit(void) {
    int16_t value;

    // Exit hibernate mode sequence
    MAX17260_Register_WriteSingle(SOFT_WAKEUP, 0x90);
    MAX17260_Register_WriteSingle(HIB_CFG, 0x00);
    MAX17260_Register_WriteSingle(SOFT_WAKEUP, 0x00);

    // Initial config values from original file
    MAX17260_Register_WriteSingle(DESIGN_CAP, 0x7FF8);
    MAX17260_Register_WriteSingle(I_CHG_TERM, 0x0000);
    MAX17260_Register_WriteSingle(V_EMPTY, 0x9661);

    // Write to ModelCfg and wait for it to clear
    MAX17260_Register_WriteSingle(MODEL_CFG, 0x8000);
    do {
        MAX17260_Register_ReadSingle(MODEL_CFG, (uint16_t*)&value);
    } while (value != 0x0000);

    uint16_t status_val;
    MAX17260_Register_ReadSingle(STATUS, &status_val);
    MAX17260_Register_WriteSingle(STATUS, status_val & ~(1 << 1)); // Clear POR bit

    MAX17260_Register_WriteSingle(HIB_CFG, 0x870C);
    
    // Write final configuration
    MAX17260_Register_WriteSingle(CONFIG2, 0x0658);
    MAX17260_Register_WriteSingle(MODEL_CFG, 0x8000);
}

//=============================================================================
// PUBLIC FUNCTION IMPLEMENTATIONS
//=============================================================================

void BatteryMonitor_Init(void) {
    i2c_init();

    // Small delay to ensure the sensor is ready after power-up.
    delay_ms(10);

    if (IsPOR()) {
        LWInit();
        ClearPOR();
    }
}

uint16_t BatteryMonitor_GetQH(void) {
    uint16_t qh_value = 0;
    MAX17260_Register_ReadSingle(QH, &qh_value);
    return qh_value;
}
