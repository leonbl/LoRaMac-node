/*!
 * \file      se-identity.h
 *
 * \brief     Secure Element identity and keys
 *
 * \copyright Revised BSD License, see section \ref LICENSE.
 *
 * \code
 *                ______                              _
 *               / _____)             _              | |
 *              ( (____  _____ ____ _| |_ _____  ____| |__
 *               \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 *               _____) ) ____| | | || |_| ____( (___| | | |
 *              (______/|_____)_|_|_| \__)_____)\____)_| |_|
 *              (C)2020 Semtech
 *
 *               ___ _____ _   ___ _  _____ ___  ___  ___ ___
 *              / __|_   _/_\ / __| |/ / __/ _ \| _ \/ __| __|
 *              \__ \ | |/ _ \ (__| ' <| _| (_) |   / (__| _|
 *              |___/ |_/_/ \_\___|_|\_\_| \___/|_|_\\___|___|
 *              embedded.connectivity.solutions===============
 *
 * \endcode
 *
 */
#ifndef __SOFT_SE_IDENTITY_H__
#define __SOFT_SE_IDENTITY_H__

#ifdef __cplusplus
extern "C" {
#endif

/*!
 ******************************************************************************
 ********************************** WARNING ***********************************
 ******************************************************************************
  The secure-element implementation supports both 1.0.x and 1.1.x LoRaWAN
  versions of the specification.
  Thus it has been decided to use the 1.1.x keys and EUI name definitions.
  The below table shows the names equivalence between versions:
               +---------------------+-------------------------+
               |       1.0.x         |          1.1.x          |
               +=====================+=========================+
               | LORAWAN_DEVICE_EUI  | LORAWAN_DEVICE_EUI      |
               +---------------------+-------------------------+
               | LORAWAN_APP_EUI     | LORAWAN_JOIN_EUI        |
               +---------------------+-------------------------+
               | LORAWAN_GEN_APP_KEY | LORAWAN_APP_KEY         |
               +---------------------+-------------------------+
               | LORAWAN_APP_KEY     | LORAWAN_NWK_KEY         |
               +---------------------+-------------------------+
               | LORAWAN_NWK_S_KEY   | LORAWAN_F_NWK_S_INT_KEY |
               +---------------------+-------------------------+
               | LORAWAN_NWK_S_KEY   | LORAWAN_S_NWK_S_INT_KEY |
               +---------------------+-------------------------+
               | LORAWAN_NWK_S_KEY   | LORAWAN_NWK_S_ENC_KEY   |
               +---------------------+-------------------------+
               | LORAWAN_APP_S_KEY   | LORAWAN_APP_S_KEY       |
               +---------------------+-------------------------+
 ******************************************************************************
 ******************************************************************************
 ******************************************************************************
 */

/*!
 * When set to 1 DevEui is LORAWAN_DEVICE_EUI
 * When set to 0 DevEui is automatically set with a value provided by MCU platform
 */
#define STATIC_DEVICE_EUI                                  1

/*!
 * end-device IEEE EUI (big endian)
 */
 #define LORAWAN_DEVICE_EUI                                 { 0x70, 0xB3, 0xD5, 0x8F, 0xF1, 0x01, 0x58, 0x89 } // Cona-SI1
// #define LORAWAN_DEVICE_EUI                                 { 0x70, 0xB3, 0xD5, 0x8F, 0xF1, 0x01, 0x58, 0xA9 } // Cona-SI2
// #define LORAWAN_DEVICE_EUI                                 { 0x70, 0xB3, 0xD5, 0x8F, 0xF1, 0x01, 0x58, 0x48 } // Cona-SI3
// #define LORAWAN_DEVICE_EUI                                 { 0x70, 0xB3, 0xD5, 0x8F, 0xF1, 0x01, 0x58, 0x56 } // Cona-SI4
// #define LORAWAN_DEVICE_EUI                                 { 0x70, 0xB3, 0xD5, 0x8F, 0xF1, 0x01, 0x58, 0x3F } // Cona-SI5
// #define LORAWAN_DEVICE_EUI                                 { 0x70, 0xB3, 0xD5, 0x8F, 0xF1, 0x01, 0x58, 0x98 } // Cona-SI6
// #define LORAWAN_DEVICE_EUI                                 { 0x70, 0xB3, 0xD5, 0x8F, 0xF1, 0x01, 0x58, 0xA5 } // Cona-TEST
/*!
 * App/Join server IEEE EUI (big endian)
 */
#define LORAWAN_JOIN_EUI                                   { 0x70, 0xB3, 0xD5, 0x7E, 0xD0, 0x01, 0x24, 0x5D } // Cona-SI all

/*!
 * Secure-element pin
 */
#define SECURE_ELEMENT_PIN                                 { 0x00, 0x00, 0x00, 0x00 }

/*!
 * When set to 1 DevAddr is LORAWAN_DEVICE_ADDRESS
 * When set to 0 DevAddr is automatically set with a value provided by a pseudo
 *      random generator seeded with a value provided by the MCU platform
 */
#define STATIC_DEVICE_ADDRESS                              0

/*!
 * Device address on the network (big endian)
 */
#define LORAWAN_DEVICE_ADDRESS                             ( uint32_t )0x00000000

#define SOFT_SE_KEY_LIST                                                                                                  \
    {                                                                                                                     \
        {                                                                                                                 \
            /*!                                                                                                           \
             * Application root key                                                                                       \
             * WARNING: FOR 1.0.x DEVICES IT IS THE \ref LORAWAN_GEN_APP_KEY                                              \
             */                                                                                                           \
            .KeyID = APP_KEY,                                                                                             \
            .KeyValue = {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F,        \
                         0x3C},                                                                                           \
        },                                                                                                                \
        {                                                                                                                 \
            /*!                                                                                                           \
             * Network root key                                                                                           \
             * WARNING: FOR 1.0.x DEVICES IT IS THE \ref LORAWAN_APP_KEY                                                  \
             */                                                                                                           \
            .KeyID = NWK_KEY,                                                                                             \
            .KeyValue = {0x76, 0x8F, 0xA0, 0xE3, 0x5E, 0x09, 0x1B, 0x57, 0x08, 0xAB, 0x26, 0xDE, 0xCB, 0x3A, 0xE8, 0x9A}, /*Cona-SI1 */\
          /*  .KeyValue = {0x0A, 0xBC, 0x9D, 0x00, 0xD0, 0xD2, 0x54, 0xFD, 0x24, 0x1C, 0xD2, 0x63, 0x10, 0x0A, 0xDA, 0xA7},*/ /*Cona-SI2 */ \
          /*  .KeyValue = {0x66, 0x59, 0xD4, 0x4A, 0xA7, 0x16, 0x04, 0x35, 0xC3, 0xEA, 0xD3, 0x33, 0x31, 0x40, 0x61, 0x5E},*/ /*Cona-SI3 */ \
          /*  .KeyValue = {0xFB, 0xAA, 0x0D, 0x11, 0x74, 0x66, 0xC1, 0xCC, 0x31, 0x20, 0xBA, 0xBA, 0x7D, 0x13, 0x8F, 0xF2},*/ /*Cona-SI4 */ \
          /*  .KeyValue = {0x7D, 0xDF, 0x5B, 0x05, 0x7C, 0xB6, 0xAC, 0x74, 0xF1, 0x41, 0x6A, 0xA2, 0xF6, 0x0F, 0x52, 0xF4},*/ /*Cona-SI5 */ \
          /*  .KeyValue = {0x7D, 0xFD, 0xC7, 0x8D, 0xDC, 0x25, 0x6B, 0xF3, 0x4F, 0x18, 0x41, 0x2F, 0xCD, 0x4B, 0x82, 0x03},*/ /*Cona-SI6 */ \
          /*    .KeyValue = {0xE0, 0xE7, 0x3D, 0x75, 0xD8, 0xB4, 0x7C, 0xC8, 0xA3, 0x8F, 0x8C, 0xAA, 0x09, 0x68, 0xF1, 0x86},*/   /*Cona TEST */ \
        },                                                                                                                \
        {                                                                                                                 \
            /*!                                                                                                           \
             * Join session integrity key (Dynamically updated)                                                           \
             * WARNING: NOT USED FOR 1.0.x DEVICES                                                                        \
             */                                                                                                           \
            .KeyID = J_S_INT_KEY,                                                                                         \
            .KeyValue = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,        \
                         0x00},                                                                                           \
        },                                                                                                                \
        {                                                                                                                 \
            /*!                                                                                                           \
             * Join session encryption key (Dynamically updated)                                                          \
             * WARNING: NOT USED FOR 1.0.x DEVICES                                                                        \
             */                                                                                                           \
            .KeyID = J_S_ENC_KEY,                                                                                         \
            .KeyValue = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,        \
                         0x00},                                                                                           \
        },                                                                                                                \
        {                                                                                                                 \
            /*!                                                                                                           \
             * Forwarding Network session integrity key                                                                   \
             * WARNING: NWK_S_KEY FOR 1.0.x DEVICES                                                                       \
             */                                                                                                           \
            .KeyID = F_NWK_S_INT_KEY,                                                                                     \
            .KeyValue = {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F,        \
                         0x3C},                                                                                           \
        },                                                                                                                \
        {                                                                                                                 \
            /*!                                                                                                           \
             * Serving Network session integrity key                                                                      \
             * WARNING: NOT USED FOR 1.0.x DEVICES. MUST BE THE SAME AS \ref LORAWAN_F_NWK_S_INT_KEY                      \
             */                                                                                                           \
            .KeyID = S_NWK_S_INT_KEY,                                                                                     \
            .KeyValue = {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F,        \
                         0x3C},                                                                                           \
        },                                                                                                                \
        {                                                                                                                 \
            /*!                                                                                                           \
             * Network session encryption key                                                                             \
             * WARNING: NOT USED FOR 1.0.x DEVICES. MUST BE THE SAME AS \ref LORAWAN_F_NWK_S_INT_KEY                      \
             */                                                                                                           \
            .KeyID = NWK_S_ENC_KEY,                                                                                       \
            .KeyValue = {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F,        \
                         0x3C},                                                                                           \
        },                                                                                                                \
        {                                                                                                                 \
            /*!                                                                                                           \
             * Application session key                                                                                    \
             */                                                                                                           \
            .KeyID = APP_S_KEY,                                                                                           \
            .KeyValue = {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F,        \
                         0x3C},                                                                                           \
        },                                                                                                                \
        {                                                                                                                 \
            /*!                                                                                                           \
             * Multicast root key (Dynamically updated)                                                                   \
             */                                                                                                           \
            .KeyID = MC_ROOT_KEY,                                                                                         \
            .KeyValue = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,        \
                         0x00},                                                                                           \
        },                                                                                                                \
        {                                                                                                                 \
            /*!                                                                                                           \
             * Multicast key encryption key (Dynamically updated)                                                         \
             */                                                                                                           \
            .KeyID = MC_KE_KEY,                                                                                           \
            .KeyValue = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,        \
                         0x00},                                                                                           \
        },                                                                                                                \
        {                                                                                                                 \
            /*!                                                                                                           \
             * Multicast group #0 root key (Dynamically updated)                                                          \
             */                                                                                                           \
            .KeyID = MC_KEY_0,                                                                                            \
            .KeyValue = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,        \
                         0x00},                                                                                           \
        },                                                                                                                \
        {                                                                                                                 \
            /*!                                                                                                           \
             * Multicast group #0 application session key (Dynamically updated)                                           \
             */                                                                                                           \
            .KeyID = MC_APP_S_KEY_0,                                                                                      \
            .KeyValue = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,        \
                         0x00},                                                                                           \
        },                                                                                                                \
        {                                                                                                                 \
            /*!                                                                                                           \
             * Multicast group #0 network session key (Dynamically updated)                                               \
             */                                                                                                           \
            .KeyID = MC_NWK_S_KEY_0,                                                                                      \
            .KeyValue = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,        \
                         0x00},                                                                                           \
        },                                                                                                                \
        {                                                                                                                 \
            /*!                                                                                                           \
             * Multicast group #1 root key (Dynamically updated)                                                          \
             */                                                                                                           \
            .KeyID = MC_KEY_1,                                                                                            \
            .KeyValue = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,        \
                         0x00},                                                                                           \
        },                                                                                                                \
        {                                                                                                                 \
            /*!                                                                                                           \
             * Multicast group #1 application session key (Dynamically updated)                                           \
             */                                                                                                           \
            .KeyID = MC_APP_S_KEY_1,                                                                                      \
            .KeyValue = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,        \
                         0x00},                                                                                           \
        },                                                                                                                \
        {                                                                                                                 \
            /*!                                                                                                           \
             * Multicast group #1 network session key (Dynamically updated)                                               \
             */                                                                                                           \
            .KeyID = MC_NWK_S_KEY_1,                                                                                      \
            .KeyValue = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,        \
                         0x00},                                                                                           \
        },                                                                                                                \
        {                                                                                                                 \
            /*!                                                                                                           \
             * Multicast group #2 root key (Dynamically updated)                                                          \
             */                                                                                                           \
            .KeyID = MC_KEY_2,                                                                                            \
            .KeyValue = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,        \
                         0x00},                                                                                           \
        },                                                                                                                \
        {                                                                                                                 \
            /*!                                                                                                           \
             * Multicast group #2 application session key (Dynamically updated)                                           \
             */                                                                                                           \
            .KeyID = MC_APP_S_KEY_2,                                                                                      \
            .KeyValue = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,        \
                         0x00},                                                                                           \
        },                                                                                                                \
        {                                                                                                                 \
            /*!                                                                                                           \
             * Multicast group #2 network session key (Dynamically updated)                                               \
             */                                                                                                           \
            .KeyID = MC_NWK_S_KEY_2,                                                                                      \
            .KeyValue = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,        \
                         0x00},                                                                                           \
        },                                                                                                                \
        {                                                                                                                 \
            /*!                                                                                                           \
             * Multicast group #3 root key (Dynamically updated)                                                          \
             */                                                                                                           \
            .KeyID = MC_KEY_3,                                                                                            \
            .KeyValue = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,        \
                         0x00},                                                                                           \
        },                                                                                                                \
        {                                                                                                                 \
            /*!                                                                                                           \
             * Multicast group #3 application session key (Dynamically updated)                                           \
             */                                                                                                           \
            .KeyID = MC_APP_S_KEY_3,                                                                                      \
            .KeyValue = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,        \
                         0x00},                                                                                           \
        },                                                                                                                \
        {                                                                                                                 \
            /*!                                                                                                           \
             * Multicast group #3 network session key (Dynamically updated)                                               \
             */                                                                                                           \
            .KeyID = MC_NWK_S_KEY_3,                                                                                      \
            .KeyValue = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,        \
                         0x00},                                                                                           \
        },                                                                                                                \
        {                                                                                                                 \
            /*!                                                                                                           \
             * All zeros key. (ClassB usage)(constant)                                                                    \
             */                                                                                                           \
            .KeyID = SLOT_RAND_ZERO_KEY,                                                                                  \
            .KeyValue = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,        \
                         0x00},                                                                                           \
        },                                                                                                                \
    },

#ifdef __cplusplus
}
#endif

#endif  //  __SOFT_SE_IDENTITY_H__
