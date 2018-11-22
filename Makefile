#sources
COMMON_C_SRCS = \
./src/delete_data.c \
./src/init_CB.c \
./src/insert_data.c \
./src/insert_link.c \
./src/resize_CB.c \
./src/report_data.c\
./src/clear_buffer.c\
./src/pop_data.c\
./main.c



#KL25Z_C_SRCS = \
#./src/system_MKL25Z4.c

#KL25Z_S_SRCS = \
#./src/startup_MKL25Z4.S

###########################################################################
#includes

vpath %.h inc

#vpath %.h inc/CMSIS

#vpath %.h inc/kl25z

###########################################################################
# Define LINUX compiler flags
LINUX_CFLAGS=  \
-Wall \
-Werror \
-g\
-Iinc/


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


project2 :$(OBJS)
	-$(CC) $(CFLAGS) -o project2 $(OBJS)

unit: 
	gcc -Wall -o unit unittest1.c src/delete_data.o src/insert_link.o src/insert_data.o src/clear_buffer.o src/resize_CB.o src/init_CB.o src/report_data.o -lcunit

clean:
	-rm *.o project2
	-rm ./src/*.o

uclean:
	-rm unit