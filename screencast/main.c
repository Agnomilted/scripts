char *strcpy(char *dest, const char *src);
int system(const char* command);
#include <stdio.h>

char screencast_cmd[512];
char path[256];

void generatepath(){
	char datestr[128];
	FILE* date = popen("date +%F_%H-%M", "r");
	fscanf(date, "%s", datestr);
	sprintf(path, "~/screencast_%s.mkv", datestr);
	fclose(date);
}

int main(int argc, char** argv){
	if (argc > 1){
		strcpy(path, argv[1]);
	}
	else {
		generatepath();
	}
	sprintf(screencast_cmd, "ffmpeg -y -f x11grab -s 1280x800 -i :0.0 -f alsa -i default %s", path);
	system(screencast_cmd);
	return 0;
}
