#ifndef LIB4JSON_H
#define LIB4JSON_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define JSON_MAX_LENGTH 64


typedef enum
{
    JSON_NUMBER = 1,
    JSON_STRING,
    JSON_BOOLEAN,
    JSON_ARRAY,
    JSON_OBJECT
}
jsonType;


typedef struct
jsonItem{
    int start;
    int end;
    jsonType type;
    jsonItem* childs;

}
jsonItem;

typedef struct
{
    jsonItem* values;
    char** keys;
    unsigned int size;
    const char* string;
}
jsonObject;



const char* getTypeJson(int type);
void toJson(jsonObject *theJson);
void printJsonString(jsonObject myJson);
void jsonStringify(jsonObject *json);
char** getJsonValues(jsonObject myJson);
jsonObject jsonParse(const char* stringed);
void printJsonParsed(jsonObject myJson);
#endif
