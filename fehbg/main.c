int system(const char* command);
int sprintf(char* str, const char* format, ...);
char* strcpy(char* dest, const char* src);


int main(int argc, char** argv){
	char fehcmd[512];
	char *path = "~/wallpapers/wallpaper3.jpg";
	if (argc > 1){
		path = argv[1];
	}
	sprintf(fehcmd, "feh --bg-scale %s", path);
	system(fehcmd);
	return 0;
}
