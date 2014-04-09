#include <stdio.h>
#include <string.h> //for strstr
 
int main( )
{
    FILE *pFile = NULL;
 
    pFile = fopen("/proc/cpuinfo", "r");
    if( pFile != NULL )
    {
        char strTemp[255];
        char *pStr;
		int count = 0;
 
        while( !feof( pFile ) )
        {
            pStr = fgets( strTemp, sizeof(strTemp), pFile );
            //printf( "%s", pStr );
			if (pStr) {
				if(strstr(pStr, "processor"))
					count++;
			} 	    
        }
		printf("count = %d\n", count);
        fclose( pFile );
    }
    else
    {
        //에러 처리
    }
 
    return 0;
}
