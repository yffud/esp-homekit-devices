idf_component_register(
    SRCS
        "adv_button.c"
    INCLUDE_DIRS
        "."
    REQUIRES
        driver
        timers_helper
        adv_i2c
)
