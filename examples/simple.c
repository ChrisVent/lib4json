#include "../lib4json.c"

int main (int args, const char *argv[]){
    // #    create the json string
    const char* json = "{\"userID\":1,\"username\":\"Admin\",\"pass\":\"Lorem123\",\"name\":\"Christian Brown\",\"admin\":true,\"Hobbies\":[\"golf\",\"rubik\"],\"Personal\":{\"fullname\":\"Christian Bartholomeus Kennedy Brown\"}}";
    // #    create json object and parse the string
    jsonObject myJson = jsonParse(json);
    // #    print the json parsed
    printJsonParsed(myJson);
    // #    print the json stringed
    //printJsonString(myJson);
    // #    save the values in array
    /*char** values = getJsonValues(myJson);
    int i;
    printf("\n====================================\n\n");
    for(i = 0 ; i < myJson.size ; i++){
        fprintf(stdout,"Value: %s\n",values[i]);
    }
    free(values);
    */
    return 0;
}
