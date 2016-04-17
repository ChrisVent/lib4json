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


<<<<<<< HEAD
typedef enum{
    ERR_JSON_BROKEN = 1,
    ERR_JSON_MEMORY,
    ERR_JSON_NOT_RECIVIED
}
jsonErr;

=======
>>>>>>> 90d9987f42c9a517a1c424b91bb6cab784484b0f
typedef struct
jsonItem{
    int start;
    int end;
    jsonType type;
<<<<<<< HEAD
    jsonItem* child;
    jsonItem* next;
    const char* key;
=======
    jsonItem* childs;
>>>>>>> 90d9987f42c9a517a1c424b91bb6cab784484b0f

}
jsonItem;

typedef struct
{
<<<<<<< HEAD
    jsonItem* first_child;
    jsonItem* last_child;
=======
    jsonItem* values;
    char** keys;
>>>>>>> 90d9987f42c9a517a1c424b91bb6cab784484b0f
    unsigned int size;
    const char* string;
}
jsonObject;



const char* getTypeJson(int type);
<<<<<<< HEAD
void fromJson(jsonObject *theJson);
=======
void toJson(jsonObject *theJson);
>>>>>>> 90d9987f42c9a517a1c424b91bb6cab784484b0f
void printJsonString(jsonObject myJson);
void jsonStringify(jsonObject *json);
char** getJsonValues(jsonObject myJson);
jsonObject jsonParse(const char* stringed);
void printJsonParsed(jsonObject myJson);
<<<<<<< HEAD
void ArrayFromJSON(jsonObject *theJson);
void ObjectFromJSON(jsonObject *theJson);
=======
>>>>>>> 90d9987f42c9a517a1c424b91bb6cab784484b0f
#endif
