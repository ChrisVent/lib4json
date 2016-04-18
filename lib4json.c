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


void ObjectFromJSON(jsonObject *theJson){
        int i, j = 0, length = strlen(theJson->string);
        for(i = 0 ; i < length; i++){
            int typeson;
            if(theJson->first_child != NULL){ typeson = theJson->first_child->type;}
            else{ typeson = 0;}
            if(theJson->string[i] == ':' && JSON_OBJECT != typeson){
                jsonItem* aux = (jsonItem*) malloc(sizeof(jsonItem));
                aux->next = NULL;
                char* temp_key = aux->key = (char*)malloc(sizeof(char));
                int k, l= 0;
                for(k = i-2; theJson->string[k] != '\"'; k--){
                    temp_key[l] = theJson->string[k];
                    aux->key = (char*)realloc(aux->key,sizeof(aux->key) + sizeof(char));
                    temp_key = (char*)realloc(temp_key,sizeof(aux->key) + sizeof(char));
                    l++;
                }
                /* reverse the key */
                int y = strlen(temp_key) -1;
                char* temp2 = (char*)malloc(sizeof(temp_key));
                int x = 0;
                while(y >= 0)
                {
                    temp2[x] = temp_key[y];
                    y--;
                    x++;

                }
                strncpy(aux->key,temp2,strlen(aux->key));
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
                }
                else{
                    aux->next = theJson->first_child;
                    theJson->first_child = aux;
                }
                /*  ---------------------------  */
                theJson->size++;
                //free(aux);
            }
            else if(theJson->string[i] == '}' && i != length-1){
                    theJson->first_child->end = i;
                    printf("%d and %d in %s",theJson->first_child->start, theJson->first_child->end,getTypeJson(theJson->first_child->type));
                    theJson->size++;
            }
            else if(theJson->string[i] == ','){
                if(theJson->string[i-1] == '\"'){
                    theJson->first_child->end = i - 1;
                }
                else if(theJson->string[i-1] == '}'){
                    if(theJson->string[i-2] == '\"'){
                        theJson->first_child->end = i - 2;
                    }
                    else{
                        theJson->first_child->end = i -1;
                    }
                }
                else{
                    theJson->first_child->end = i;
                }
            }
            else if(theJson->string[i] == '}' && i == length-1){
                if(theJson->string[i-1] == '\"'){
                    theJson->first_child->end = i -1;
                }
                else{
                    theJson->first_child->end = i;
                }

            }
        }
}


void ArrayFromJSON(jsonObject *theJson){
    //
}
void fromJson(jsonObject *theJson){
    if(theJson->string && theJson->string[0] == '{'){
        ObjectFromJSON(theJson);
    }
    else if(theJson->string && theJson->string[0] == '[' && theJson->string[strlen(theJson->string) - 1] == ']'){
        ArrayFromJSON(theJson);
    }
    else{
        fprintf(stderr, "[!] The JSON recivied is broken.\n");
        exit(ERR_JSON_BROKEN);
    }
}


void printJsonString(jsonObject myJson){
    if(!myJson.string){
        fprintf(stderr, "[!] Error printing the JSON string\n");
        exit(ERR_JSON_NOT_RECIVIED);
    }
    else{
        printf("%s",myJson.string);
    }
}

void jsonStringify(jsonObject *json){};
const char* getValueJSON(const char* key){ return "test";};

jsonObject jsonParse(const char* stringed){
    if(strlen(stringed) < 1){
        fprintf(stderr, "[!] Error accepting the JSON string\n");
        exit(ERR_JSON_NOT_RECIVIED);
    }
    jsonObject json;
    json.string = (char*)malloc(sizeof(char) * strlen(stringed));
    strncpy(json.string,stringed,strlen(stringed));
    json.size = 0;
    json.first_child = NULL;
    fromJson(&json);
    return json;
};


char** getJsonValues(jsonObject myJson){
    int i;
    char** jsonValues;
    jsonValues = (char**)malloc(sizeof(char*) * myJson.size);
    if(jsonValues == NULL){
        fprintf(stderr,"[!] Error Saving values\n");
        exit(ERR_JSON_MEMORY);
    }

    jsonItem* aux = (jsonItem*)malloc(sizeof(jsonItem));
    aux = myJson.first_child;
    while(aux != NULL && i < myJson.size){
        jsonValues[i] = (char*)malloc(sizeof(char) * aux->end - aux->start);
        sprintf(jsonValues[i],"%.*s",aux->end - aux->start,myJson.string + aux->start);
        aux = aux->next;
        i++;
    }
    return jsonValues;
}


void printJsonParsed(jsonObject myJson){
    int i;
    if(strlen(myJson.string) < 1){
        fprintf(stderr, "[!] Error printing the JSON Parsed.\n");
        exit(ERR_JSON_NOT_RECIVIED);
    }
    jsonItem* aux = (jsonItem*)malloc(sizeof(jsonItem));
    aux = myJson.first_child;
    printf("\n");
    while(aux != NULL){
        printf("[ %s ]: ",aux->key);
        fprintf(stdout,"%.*s\t(Type: %s)\n",aux->end - aux->start ,myJson.string + aux->start, getTypeJson(aux->type));
        aux = aux->next;
    }
}


jsonObject initJSON(){
    jsonObject json;
    json.size = 0;
    json.first_child = NULL;
    json.string = NULL;
    return json;
}

