#ifndef LIB4JSON_H
#define LIB4JSON_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define JSON_MAX_LENGTH 128

typedef enum
{
    JSON_NUMBER = 1,
    JSON_STRING,
    JSON_BOOLEAN,
    JSON_ARRAY,
    JSON_OBJECT
}
jsonType;

typedef enum{
    ERR_JSON_BROKEN = 1,
    ERR_JSON_MEMORY,
    ERR_JSON_NOT_RECIVIED
}
jsonErr;

typedef struct
jsonItem{
    int start;
    int end;
    jsonType type;
    jsonItem* child;
    jsonItem* next;
    char* key;

}
jsonItem;

typedef struct
{
    jsonItem* first_child;
    unsigned int size;
    char* string;
}
jsonObject;



const char* getTypeJson(int type);
void fromJson(jsonObject *theJson);
void printJsonString(jsonObject myJson);
void jsonStringify(jsonObject *json);
char** getJsonValues(jsonObject myJson);
jsonObject jsonParse(const char* stringed);
void printJsonParsed(jsonObject myJson);
void ArrayFromJSON(jsonObject *theJson);
void ObjectFromJSON(jsonObject *theJson);
jsonObject initJSON();
void addJsonItem_String(jsonObject*, const char*, const char*);
void addJsonItem_Number(jsonObject*, const char*, int);
void addJsonItem_Boolean(jsonObject*, const char*, bool);
#endif
