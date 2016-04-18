#include "../lib4json.c"

int main (int args, const char *argv[]){
    // #    create the json string
    const char* json = "{\"userID\":1,\"username\":\"Admin\",\"pass\":\"Lorem123\",\"name\":\"Christian Brown\",\"admin\":true,\"Hobbies\":[\"golf\",\"rubik\"]}";
    // #    create json object and parse the string
    jsonObject myJson = jsonParse(json);
    //addJsonItem_String(&myJson,"foo","bar"); // no do this! (in beta);
    printJsonParsed(myJson);

    //save the values in array
    char** values = getJsonValues(myJson);
    printf("\n====================================\n\n");
    int j;
    for(j = 0 ; j < myJson.size ; j++){
        fprintf(stdout,"Value: %s\n",values[j]);
    }
    free(values);

    //save the keys in array
    char** keys = getJsonKeys(myJson);
    int i;
    printf("\n====================================\n\n");
    for(i = 0 ; i < myJson.size ; i++){
        fprintf(stdout,"Key: %s\n",keys[i]);
    }
    free(keys);






    // empty json for add Items (coming)
    jsonObject AnotherJson = initJSON();
    return 0;
}
