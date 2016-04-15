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
{
    int start;
    int end;
    jsonType type;
}
jsonItem;

typedef struct
{
    jsonItem values[JSON_MAX_LENGTH];
    char* keys[JSON_MAX_LENGTH];
    unsigned int size;
    const char* string;
}
jsonObject;


const char* getTypeJson(int type){
    switch(type){
        case JSON_NUMBER:
            return "Number";
            break;
        case JSON_STRING:
            return "String";
            break;
        case JSON_BOOLEAN:
            return "Boolean";
            break;
        case JSON_ARRAY:
            return "Array";
            break;
        case JSON_OBJECT:
            return "Object";
            break;
    }
}
void toJson(jsonObject *theJson){
    int i, j = 0, length = strlen(theJson->string);
    for(i = 0 ; i < length && j < JSON_MAX_LENGTH; i++){
        if(theJson->string[i] == ':'){
            if(theJson->string[i+1] == '\"'){
                theJson->values[j].start = i + 2;
                theJson->values[j].type = JSON_STRING;
            }
            else{
                theJson->values[j].start = i + 1;
                if(theJson->string[i+1] == 't' || theJson->string[i+1] == 'f'){
                    theJson->values[j].type = JSON_BOOLEAN;
                }
                else{
                    theJson->values[j].type = JSON_NUMBER;
                }
            }
            theJson->size++;
        }
        if(theJson->string[i] == ','){
            if(theJson->string[i-1] == '\"'){
                theJson->values[j].end = i - 1;
            }
            else{
                theJson->values[j].end = i;
            }

            j++;
        }
        if(theJson->string[i] == '}'){
            if(theJson->string[i-1] == '\"'){
                theJson->values[j].end = i - 1;
            }
            else{
                theJson->values[j].end = i;
            }
            break;
        }
    }
}


void printJsonString(jsonObject myJson){
    char buff[255];
    sprintf(buff,"%s\n",myJson.string);
    char *stringed = (char*)malloc(sizeof(char) * strlen(buff));
    strncpy(stringed,buff,strlen(buff));
    printf("%s",stringed);
    free(stringed);
}

void jsonStringify(jsonObject *json){};

jsonObject jsonParse(const char* stringed){
    jsonObject json;
    json.string = (char*)malloc(sizeof(char) * strlen(stringed));
    json.string = stringed;
    json.size = 0;
    toJson(&json);
    return json;
};


char** getJsonValues(jsonObject myJson){
    int i;
    char** jsonValues;
    jsonValues = (char**)malloc(sizeof(char*) * myJson.size);
    if(jsonValues == NULL){
        printf("[!] Error\n\n\n");
    }
    for(i = 0 ; i < myJson.size ; i++){
        jsonValues[i] = (char*)malloc(sizeof(char)*128);
        sprintf(jsonValues[i],"%.*s",myJson.values[i].end - myJson.values[i].start,myJson.string + myJson.values[i].start);
    }
    return jsonValues;
}


void printJsonParsed(jsonObject myJson){
    int i;
    for(i = 0 ; i < myJson.size ; i++){
        printf("%.*s\t\t(Type: %s)\n",myJson.values[i].end - myJson.values[i].start,myJson.string + myJson.values[i].start, getTypeJson(myJson.values[i].type));
    }
}



int main (int args, const char *argv[]){
    // #    create the json string
    const char* json = "{\"userID\":1,\"username\":\"Admin\",\"pass\":\"Lorem123\",\"name\":\"Christian Brown\",\"admin\":true}";
    // #    create json object and parse the string
    jsonObject myJson = jsonParse(json);
    // #    print the json parsed
    //printJsonParsed(myJson);
    // #    print the json stringed
    //printJsonString(myJson);

    // #    save the values in array
    char** values = getJsonValues(myJson);
    int i;
    for(i = 0 ; i < myJson.size ; i++){
        printf("Value: %s\n",values[i]);
    }
    return 0;
}
