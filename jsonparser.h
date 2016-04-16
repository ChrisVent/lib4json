#ifndef JSONPARSER_H
#define JSONPARSER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef JSON_MAX_LENGTH
#define JSON_MAX_LENGTH 64
#endif


#ifndef JSON_TYPE
#define JSON_TYPE
typedef enum
{
    JSON_NUMBER = 1,
    JSON_STRING,
    JSON_BOOLEAN,
    JSON_ARRAY,
    JSON_OBJECT
}
jsonType;
#endif


#ifndef JSON_ITEM
#define JSON_ITEM
typedef struct
{
    int start;
    int end;
    jsonType type;
}
jsonItem;
#endif

#ifndef JSON_OBJECTP
#define JSON_OBJECTP
typedef struct
{
    jsonItem values[JSON_MAX_LENGTH];
    char* keys[JSON_MAX_LENGTH];
    unsigned int size;
    const char* string;
}
jsonObject;

#endif



const char* getTypeJson(int type);
void toJson(jsonObject *theJson);
void printJsonString(jsonObject myJson);
void jsonStringify(jsonObject *json);
char** getJsonValues(jsonObject myJson);
jsonObject jsonParse(const char* stringed);
void printJsonParsed(jsonObject myJson);
#endif
