#include "main.h"
#include "psp2-resume.h"

#include <psp2/kernel/threadmgr.h>
#include <psp2/power.h>

int DATA_Resume(FILE *f, const char *fileName)
{
	if (f)
	{
		UTIL_CloseFile(f);
		f = UTIL_OpenRequiredFile(fileName);
	}
}

int VITA_SuspendCallback(int notifyId, int notifyCount, int powerInfo, void *common)
{
	if ((powerInfo >> 4) & SCE_POWER_CB_RESUMING) // FIXME: work but... meh ?
	{
		printf("Resuming...\n");

		DATA_Resume(gpGlobals->f.fpFBP, "fbp.mkf");
		DATA_Resume(gpGlobals->f.fpMGO, "mgo.mkf");
		DATA_Resume(gpGlobals->f.fpBALL, "ball.mkf");
		DATA_Resume(gpGlobals->f.fpDATA, "data.mkf");
		DATA_Resume(gpGlobals->f.fpF, "f.mkf");
		DATA_Resume(gpGlobals->f.fpFIRE, "fire.mkf");
		DATA_Resume(gpGlobals->f.fpRGM, "rgm.mkf");
		DATA_Resume(gpGlobals->f.fpSSS, "sss.mkf");

		gpGlobals->lpObjectDesc = gConfig.fIsWIN95 ? NULL : PAL_LoadObjectDesc("desc.dat");

		AUDIO_Resume();
	}
	return 0;
}

int VITA_RegisterCallbackThread(SceSize args, void *argp)
{
	SceUID cbid;
	cbid = sceKernelCreateCallback("Suspend Callback", 0, VITA_SuspendCallback, NULL);
	scePowerRegisterCallback(cbid);
	while (1) // FIXME: to recode
	{
		sceKernelDelayThreadCB(0);
	}
	return 0;
}

int VITA_SetupCallbacks(void)
{
	SceUID thid;
	thid = sceKernelCreateThread("update_thread", VITA_RegisterCallbackThread, 0x10000100, 0x10000, 0, 0, NULL);
	if (thid >= 0)
	{
		sceKernelStartThread(thid, 0, 0);
	}
	return thid;
}
