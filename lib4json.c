#include "lib4json.h"

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
        default:
            return "Undefined";
    }
}

void toJson(jsonObject *theJson){
    if(!theJson->string){
        fprintf(stderr,"[!]Error parsing the Json.\n");
        exit(2);
    }
    theJson->values = (jsonItem*) malloc(sizeof(jsonItem));
    int i, j = 0, length = strlen(theJson->string);
    for(i = 0 ; i < length && j < JSON_MAX_LENGTH; i++){
        if(theJson->string[i] == ':'){
            theJson->values = (jsonItem*) realloc(theJson->values,sizeof(theJson->values) + sizeof(jsonItem));
            if(theJson->string[i+1] == '\"'){
                theJson->values[j].start = i + 2;
                theJson->values[j].type = JSON_STRING;
            }
            else if(theJson->string[i] == '{'){
                theJson->values[j].type = JSON_OBJECT;
            }
            else if(theJson->string[i] == '['){
                theJson->values[j].type = JSON_ARRAY;
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
    if(myJson.string){
        char buff[255];
        sprintf(buff,"%s\n",myJson.string);
        char *stringed = (char*)malloc(sizeof(char) * strlen(buff));
        strncpy(stringed,buff,strlen(buff));
        printf("%s",stringed);
        free(stringed);
    }
    else{
        fprintf(stderr, "[!] Error printing the JSON string\n");
        exit(2);
    }
}

void jsonStringify(jsonObject *json){};

jsonObject jsonParse(const char* stringed){
    if(strlen(stringed) < 1){
        fprintf(stderr, "[!] Error accepting the JSON string\n");
        exit(2);
    }
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
        fprintf(stderr,"[!] Error Saving values\n");
        exit(2);
    }
    for(i = 0 ; i < myJson.size ; i++){
        jsonValues[i] = (char*)malloc(sizeof(char)*128);
        sprintf(jsonValues[i],"%.*s",myJson.values[i].end - myJson.values[i].start,myJson.string + myJson.values[i].start);
    }
    return jsonValues;
}


void printJsonParsed(jsonObject myJson){
    int i;
    if(strlen(myJson.string) < 1){
        fprintf(stderr, "[!] Error printing the JSON Parsed.\n");
        exit(3);
    }
    for(i = 0 ; i < myJson.size ; i++){
        fprintf(stdout,"%.*s\t\t(Type: %s)\n",myJson.values[i].end - myJson.values[i].start,myJson.string + myJson.values[i].start, getTypeJson(myJson.values[i].type));
    }
}

