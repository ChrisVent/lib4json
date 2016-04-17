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

<<<<<<< HEAD

void ObjectFromJSON(jsonObject *theJson){
    theJson->first_child = NULL;
        int i, j = 0, length = strlen(theJson->string);
        for(i = 0 ; i < length; i++){
            int typeson;
            if(theJson->first_child != NULL){ typeson = theJson->first_child->type;}
            else{ typeson = 0;}
            if(theJson->string[i] == ':' && JSON_OBJECT != typeson){
                jsonItem* aux = (jsonItem*) malloc(sizeof(jsonItem));
                aux->next = NULL;
                if(theJson->string[i+1] == '\"'){
                    aux->start = i + 2;
                    aux->type = JSON_STRING;
                }
                else if(theJson->string[i+1] == '{'){
                    aux->type = JSON_OBJECT;
                    aux->start = i+1;
                }
                else if(theJson->string[i+1] == '['){
                    aux->start = i+1;
                    aux->type = JSON_ARRAY;
                }
                else{
                    aux->start = i + 1;
                    if(theJson->string[i+1] == 't' || theJson->string[i+1] == 'f'){
                        aux->type = JSON_BOOLEAN;
                    }
                    else{
                        aux->type = JSON_NUMBER;
                    }
                }
                /* ----- SAVE THE VALUE ------ */
                if(aux == NULL){
                    fprintf(stderr, "[!] Error saving the values\n");
                    exit(ERR_JSON_MEMORY);
                }
                if(theJson->first_child == NULL){
                    theJson->first_child = aux;
                    aux->next = NULL;
                }
                else{
                    aux->next = theJson->first_child;
                    theJson->first_child = aux;
                }
                /*  ---------------------------  */
                theJson->size++;
                //free(aux);
            }
            if(theJson->string[i] == ','){
                if(theJson->string[i-1] == '\"'){
                    theJson->first_child->end = i - 1;
                }
                else{
                    theJson->first_child->end = i;
                }
                j++;
            }
            if(theJson->string[i] == '}' && i == strlen(theJson->string) -1 ){
                if(theJson->string[i-1] == '\"'){
                    theJson->first_child->end = i - 1;
                }
                else{
                    theJson->first_child->end = i;
                }
                break;
            }
        }
}


void ArrayFromJSON(jsonObject *theJson){
    //
}
void fromJson(jsonObject *theJson){
    if(theJson->string && theJson->string[0] == '{' && theJson->string[strlen(theJson->string) - 1] == '}'){
        ObjectFromJSON(theJson);
    }
    else if(theJson->string && theJson->string[0] == '[' && theJson->string[strlen(theJson->string) - 1] == ']'){
        ArrayFromJSON(theJson);
    }
    else{
        fprintf(stderr, "[!] The JSON recivied is broken.\n");
        exit(ERR_JSON_BROKEN);
=======
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
>>>>>>> 90d9987f42c9a517a1c424b91bb6cab784484b0f
    }
}


void printJsonString(jsonObject myJson){
<<<<<<< HEAD
    if(!myJson.string){
        fprintf(stderr, "[!] Error printing the JSON string\n");
        exit(ERR_JSON_NOT_RECIVIED);
    }
    else{
        printf("%s",myJson.string);
=======
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
>>>>>>> 90d9987f42c9a517a1c424b91bb6cab784484b0f
    }
}

void jsonStringify(jsonObject *json){};
<<<<<<< HEAD
const char* getValueJSON(const char* key){ return "test";};
=======
>>>>>>> 90d9987f42c9a517a1c424b91bb6cab784484b0f

jsonObject jsonParse(const char* stringed){
    if(strlen(stringed) < 1){
        fprintf(stderr, "[!] Error accepting the JSON string\n");
<<<<<<< HEAD
        exit(ERR_JSON_NOT_RECIVIED);
=======
        exit(2);
>>>>>>> 90d9987f42c9a517a1c424b91bb6cab784484b0f
    }
    jsonObject json;
    json.string = (char*)malloc(sizeof(char) * strlen(stringed));
    json.string = stringed;
    json.size = 0;
<<<<<<< HEAD
    fromJson(&json);
=======
    toJson(&json);
>>>>>>> 90d9987f42c9a517a1c424b91bb6cab784484b0f
    return json;
};


char** getJsonValues(jsonObject myJson){
    int i;
    char** jsonValues;
    jsonValues = (char**)malloc(sizeof(char*) * myJson.size);
    if(jsonValues == NULL){
        fprintf(stderr,"[!] Error Saving values\n");
<<<<<<< HEAD
        exit(ERR_JSON_MEMORY);
    }

    jsonItem* aux = (jsonItem*)malloc(sizeof(jsonItem));
    aux = myJson.first_child;
    while(aux != NULL && i < myJson.size){
        jsonValues[i] = (char*)malloc(sizeof(char) * aux->end - aux->start);
        sprintf(jsonValues[i],"%.*s",aux->end - aux->start,myJson.string + aux->start);
        aux = aux->next;
        i++;
=======
        exit(2);
    }
    for(i = 0 ; i < myJson.size ; i++){
        jsonValues[i] = (char*)malloc(sizeof(char)*128);
        sprintf(jsonValues[i],"%.*s",myJson.values[i].end - myJson.values[i].start,myJson.string + myJson.values[i].start);
>>>>>>> 90d9987f42c9a517a1c424b91bb6cab784484b0f
    }
    return jsonValues;
}


void printJsonParsed(jsonObject myJson){
    int i;
    if(strlen(myJson.string) < 1){
        fprintf(stderr, "[!] Error printing the JSON Parsed.\n");
<<<<<<< HEAD
        exit(ERR_JSON_NOT_RECIVIED);
    }
    jsonItem* aux = (jsonItem*)malloc(sizeof(jsonItem));
    aux = myJson.first_child;
    printf("\n");
    while(aux != NULL){
        fprintf(stdout,"%.*s\t\t(Type: %s)\n",aux->end - aux->start ,myJson.string + aux->start, getTypeJson(aux->type));
        aux = aux->next;
=======
        exit(3);
    }
    for(i = 0 ; i < myJson.size ; i++){
        fprintf(stdout,"%.*s\t\t(Type: %s)\n",myJson.values[i].end - myJson.values[i].start,myJson.string + myJson.values[i].start, getTypeJson(myJson.values[i].type));
>>>>>>> 90d9987f42c9a517a1c424b91bb6cab784484b0f
    }
}

