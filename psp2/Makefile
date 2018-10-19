TARGET   = sdlpal
TITLE_ID = SDLPAL001

INTER    = .vita

PREFIX   = arm-vita-eabi

SOURCES  = . .. ../adplug
CFILES   = $(foreach dir, $(SOURCES), $(wildcard $(dir)/*.c))
CPPFILES = $(foreach dir, $(SOURCES), $(wildcard $(dir)/*.cpp))
OFILES   = $(CFILES:.c=$(INTER).o) $(CPPFILES:.cpp=$(INTER).o)

CCFLAGS  = -Wl,-q -O3 -g -I. -I.. -I$(VITASDK)/$(PREFIX)/include/SDL2 -I$(VITASDK)/$(PREFIX)/include/vitashaders
CXXFLAGS = $(CCFLAGS) -std=c++11
CFLAGS   = $(CCFLAGS) -std=gnu99 -D_GNU_SOURCE
LDFLAGS  = -lSDL2 -lvita2d_fbo -lvitashaders \
	-lSceAppUtil_stub -lSceAudio_stub -lSceCommonDialog_stub \
	-lSceCtrl_stub -lSceDisplay_stub -lSceGxm_stub -lSceHid_stub \
	-lScePower_stub -lSceSysmodule_stub -lSceTouch_stub

all: $(TARGET).vpk

$(TARGET).vpk: eboot.bin
	vita-mksfoex -s TITLE_ID=$(TITLE_ID) "$(TARGET)" param.sfo
	vita-pack-vpk -s param.sfo -b eboot.bin \
	-a res/icon0.png=sce_sys/icon0.png \
	-a res/bg.png=sce_sys/livearea/contents/bg.png \
	-a res/startup.png=sce_sys/livearea/contents/startup.png \
	-a res/template.xml=sce_sys/livearea/contents/template.xml $@

eboot.bin: $(TARGET).velf
	vita-make-fself -c -s $< eboot.bin

%.velf: %.elf
	vita-elf-create $< $@

$(TARGET).elf: $(OFILES)
	@$(PREFIX)-g++ $(CXXFLAGS) $(OFILES) -o $@ $(LDFLAGS)

%$(INTER).o: %.c
	@echo [CC] $<
	@$(PREFIX)-gcc $(CFLAGS) -c $< -o $@

%$(INTER).o: %.cpp
	@echo [CC] $<
	@$(PREFIX)-g++ $(CXXFLAGS) -c $< -o $@

vpksend: $(TARGET).vpk
	curl -T $(TARGET).vpk ftp://$(VITAIP):1337/ux0:/
	@echo "Sent."

send: eboot.bin
	curl -T eboot.bin ftp://$(VITAIP):1337/ux0:/app/$(TITLE_ID)/
	@echo "Sent."

clean:
	@rm -rf $(OFILES) $(TARGET).velf $(TARGET).elf $(TARGET).vpk eboot.bin param.sfo
