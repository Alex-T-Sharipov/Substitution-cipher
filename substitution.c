#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if(strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    char key[26];
    
    for(int i = 0; i < 26; i++)
    {
        if(toupper(argv[1][i]) < 'A' || toupper(argv[1][i]) > 'Z')
        {
            printf("Invalid key\n");
            return 1;
        }
        else
        {
            if(i == 0)
            {
                key[i] = argv[1][i];
            }
            else
            {
                for(int j = 0; j < i; j ++)
                {
                    if(key[j] == argv[1][i])
                    {
                        printf("Invalid key\n");
                        return 1;
                    }
                    else
                    {
                        key[i] = argv[1][i];
                    }
                }
            }
        }
    }
    
    char alphabetl[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char alphabetu[26];
    char keyl[26];
    char keyu[26];

    
    for(int i = 0; i < 26; i++)
    {
        keyl[i] = tolower(key[i]);
        keyu[i] = toupper(key[i]);
        alphabetu[i] = toupper(alphabetl[i]);
    }
    
    
    string p = get_string("plaintext: ");
    printf("ciphertext: ");
    
    for(int i = 0; i < strlen(p); i++)
    {
        char c = p[i];
        bool t = true;
        
        for(int j = 0; j < 26; j++)
        {
            if(c == alphabetl[j])
            {
                printf("%c", keyl[j]);
                t = false;
            }
            else if(c == alphabetu[j])
            {
                printf("%c", keyu[j]);
                t = false;
            }
        }
        
        if(t)
        {
            printf("%c", p[i]);
        }
        
    }
    printf("\n");
    return 0;
    
}