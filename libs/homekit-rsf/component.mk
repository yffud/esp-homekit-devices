# Component makefile for homekit

ifndef wolfssl_ROOT
$(error Please include wolfssl component prior to homekit)
endif

ifndef cJSON_ROOT
$(error Please include cJSON component prior to homekit)
endif

ifndef http-parser_ROOT
$(error Please include http-parser component prior to homekit)
endif

INC_DIRS += $(homekit_ROOT)/include

homekit_INC_DIR = $(homekit_ROOT)/include $(homekit_ROOT)/src
homekit_SRC_DIR = $(homekit_ROOT)/src

$(eval $(call component_compile_rules,homekit))

EXTRA_WOLFSSL_CFLAGS = \
	-DWOLFCRYPT_HAVE_SRP \
	-DWOLFSSL_SHA512 \
	-DWOLFSSL_BASE64_ENCODE \
	-DNO_MD5 \
	-DNO_SHA \
	-DHAVE_HKDF \
	-DHAVE_CHACHA \
	-DHAVE_POLY1305 \
	-DHAVE_ED25519 \
	-DHAVE_CURVE25519 \
	-DNO_SESSION_CACHE \
	-DRSA_LOW_MEM \
	-DGCM_SMALL \
	-DUSE_SLOW_SHA \
	-DUSE_SLOW_SHA2 \
	-DUSE_SLOW_SHA256 \
	-DUSE_SLOW_SHA512 \
	-DWOLFCRYPT_ONLY \
	-DTFM_TIMING_RESISTANT

ifeq ($(HOMEKIT_SMALL),1)
EXTRA_WOLFSSL_CFLAGS += \
	-DCURVE25519_SMALL \
	-DED25519_SMALL
endif

wolfssl_CFLAGS += $(EXTRA_WOLFSSL_CFLAGS)
homekit_CFLAGS += $(EXTRA_WOLFSSL_CFLAGS)
