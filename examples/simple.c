#include "../lib4json.c"

int main (int args, const char *argv[]){
    // #    create the json string
    const char* json = "{\"userID\":1,\"username\":\"Admin\",\"pass\":\"Lorem123\",\"name\":\"Christian Brown\",\"Hobbies\":[\"golf\",\"rubik\"],\"admin\":true,\"foo\":\"bar\"}";

    //const char* json = "{\"name\":\"Clark\",\"Last Name\":\"Ken\"}";
    //const char* json = "{\"name\":\"Clark\"}";
    // #    create json object and parse the string
    jsonObject myJson = jsonParse(json);
    //addJsonItem_String(&myJson,"foo","bar");
    printJsonString(myJson);
    jsonObject otherJson = jsonParse(myJson.string);
    printJsonString(otherJson);
    // #    print the json parsed
    printJsonParsed(otherJson);
    // #    print the json stringed
    // #    save the values in array
    /*char** values = getJsonValues(myJson);
    int i;
    printf("\n====================================\n\n");
    for(i = 0 ; i < myJson.size ; i++){
        fprintf(stdout,"Value: %s\n",values[i]);
    }
    free(values);
    */


    jsonObject AnotherJson = initJSON();
    return 0;
}
