#sources
COMMON_C_SRCS = \
./src/delete_CB.c \
./src/init_CB.c \
./src/insert_data.c \
./src/insert_link.c \
./src/resize_CB.c \
./src/report_data.c\
./src/clear_buffer.c\
./src/pop_data.c\
./main.c




KL25Z_C_SRCS = \
./src/system_MKL25Z4.c\
./src/uart.c

KL25Z_S_SRCS = \
./src/startup_MKL25Z4.S

###########################################################################
#includes

vpath %.h inc/common 

vpath %.h inc/CMSIS

vpath %.h inc/kl25z

###########################################################################
# Define LINUX compiler flags
LINUX_CFLAGS=  \
-Wall \
-Werror \
-g\
-Iinc/common

# Define KL25Z compiler flags
KL25Z_CFLAGS= \
-mcpu=cortex-m0plus \
-march=armv6-m \
-mthumb \
-mfloat-abi=soft \
-mfpu=fpv4-sp-d16 \
-specs=nosys.specs\
-fmessage-length=0\
-fdata-sections\
-Iinc/common\
-Iinc/CMSIS\
-Iinc/kl25z\
-Iplatform

KL25Z_LDFLAGS=-T ./platform/MKL25Z128xxx4_flash.ld

##########################################################################

ifeq ($(PLATFORM),LINUX)
CC=gcc
CFLAGS=$(LINUX_CFLAGS)
SOURCES=$(COMMON_C_SRCS)

else ifeq ($(PLATFORM),KL25Z) 
CC=arm-none-eabi-gcc 
CFLAGS= $(KL25Z_CFLAGS)
SOURCES=$(COMMON_C_SRCS) $(KL25Z_C_SRCS) $(KL25Z_S_SRCS)
LDFLAGS=$(KL25Z_LDFLAGS)

endif

ifeq ($(PLATFORM),KL25Z)
OBJS:= $(COMMON_C_SRCS:.c=.o) $(KL25Z_C_SRCS:.c=.o) $(KL25Z_S_SRCS:.S=.o)
else
OBJS:= $(SOURCES:.c=.o)
endif

%.o: %.c
	-$(CC) $(CFLAGS) -c $< -o $@ 

%.o: %.S
	-$(CC) $(CFLAGS) -c $< -o $@ 


char_histogram :$(OBJS)
	-$(CC) $(CFLAGS) $(LDFLAGS) -Xlinker -Map=char_histogram.map -o char_histogram.elf $(OBJS)

unit: 
	gcc -Wall -o unit unittest1.c src/delete_CB.o src/insert_link.o src/insert_data.o src/clear_buffer.o src/resize_CB.o src/init_CB.o src/report_data.o src/pop_data.o -lcunit

clean:
	-rm *.o char_histogram.elf
	-rm ./src/*.o

uclean:
	-rm unit
