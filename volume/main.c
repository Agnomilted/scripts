#include <stdio.h>
#include <stdlib.h>

int main(){
	char setvolumecmd[128];
	char selectedvolume[10];
	char dmenucmd[128];
	char* volumes = "0%\n10%\n20%\n30%\n40%\n50%\n60%\n70%\n80%\n90%\n100%";

	sprintf(dmenucmd, "echo \"%s\" | dmenu", volumes);
	FILE* dmenustream = popen(dmenucmd, "r");
	fscanf(dmenustream, "%s", selectedvolume);
	pclose(dmenustream);
	sprintf(setvolumecmd, "amixer sset Master %s", selectedvolume);
	system(setvolumecmd);

	return 0;
}
