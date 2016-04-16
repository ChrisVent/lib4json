#include "../jsonparser.c"

int main (int args, const char *argv[]){
    // #    create the json string
    const char* json = "{\"userID\":1,\"username\":\"Admin\",\"pass\":\"Lorem123\",\"name\":\"Christian Brown\",\"admin\":true}";
    // #    create json object and parse the string
    jsonObject myJson = jsonParse(json);
    // #    print the json parsed
    printJsonParsed(myJson);
    // #    print the json stringed
    //printJsonString(myJson);

    // #    save the values in array
    char** values = getJsonValues(myJson);
    int i;
    for(i = 0 ; i < myJson.size ; i++){
        fprintf(stdout,"Value: %s\n",values[i]);
    }
    free(values);
    return 0;
}
