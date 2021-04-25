TARGET    = sdlpal

INTER     = .switch

PREFIX    = $(DEVKITA64)/bin/aarch64-none-elf

SOURCES   = . .. ../adplug ../timidity
CFILES    = $(foreach dir, $(SOURCES), $(wildcard $(dir)/*.c))
CPPFILES  = $(foreach dir, $(SOURCES), $(wildcard $(dir)/*.cpp))
OFILES    = $(CFILES:.c=$(INTER).o) $(CPPFILES:.cpp=$(INTER).o)

CCFLAGS   = -D__SWITCH__ -march=armv8-a -mtune=cortex-a57 -mtp=soft -fPIE -O3 -I. -I.. -I../timidity
CCFLAGS  += -I$(DEVKITPRO)/portlibs/switch/include -I$(DEVKITPRO)/portlibs/switch/include/SDL2 -I$(DEVKITPRO)/libnx/include
CXXFLAGS  = $(CCFLAGS) -std=c++11
CFLAGS    = $(CCFLAGS) -std=gnu99 -D_GNU_SOURCE
LDFLAGS   = -L/opt/devkitpro/portlibs/switch/lib -lSDL2 -L/opt/devkitpro/libnx/lib -lGLESv2
LDFLAGS  += -lEGL -lglapi -ldrm_nouveau -lnx -specs=$(DEVKITPRO)/libnx/switch.specs

all: $(TARGET).nro

$(TARGET).nro: $(TARGET).elf
	nacptool --create "sdlpal" "usineur" "1.0-nx" $(TARGET).nacp
	elf2nro $(TARGET).elf $(TARGET).nro --icon=icon.jpg --nacp=$(TARGET).nacp

$(TARGET).elf: $(OFILES)
	@$(PREFIX)-g++ $(CXXFLAGS) $(OFILES) -o $@ $(LDFLAGS)

%$(INTER).o: %.c
	@echo [CC] $<
	@$(PREFIX)-gcc $(CFLAGS) -c $< -o $@

%$(INTER).o: %.cpp
	@echo [CC] $<
	@$(PREFIX)-g++ $(CXXFLAGS) -c $< -o $@

nxlink: $(TARGET).nro
	nxlink -a $(SWITCHIP) $(TARGET).nro -s -p $(TARGET)/$(TARGET).nro

clean:
	@rm -rf $(OFILES) $(TARGET).nro $(TARGET).nacp $(TARGET).elf
