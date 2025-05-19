#include <unistd.h>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
const char *pName = "./pipe";
//stdandard output flush when meeting endline,ordinary file flush when is filled