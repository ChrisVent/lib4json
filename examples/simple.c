<<<<<<< HEAD
#include "../lib4json.c"

int main (int args, const char *argv[]){
    // #    create the json string
    const char* json = "{\"userID\":1,\"username\":\"Admin\",\"pass\":\"Lorem123\",\"name\":\"Christian Brown\",\"admin\":true,\"array\":[\"julia\",\"robert\"],\"Object\":{\"julia\":\"robert\"}}";
=======
#include "../jsonparser.c"

int main (int args, const char *argv[]){
    // #    create the json string
    const char* json = "{\"userID\":1,\"username\":\"Admin\",\"pass\":\"Lorem123\",\"name\":\"Christian Brown\",\"admin\":true}";
>>>>>>> 90d9987f42c9a517a1c424b91bb6cab784484b0f
    // #    create json object and parse the string
    jsonObject myJson = jsonParse(json);
    // #    print the json parsed
    printJsonParsed(myJson);
    // #    print the json stringed
    //printJsonString(myJson);
<<<<<<< HEAD
    // #    save the values in array
    char** values = getJsonValues(myJson);
    int i;
    printf("\n====================================\n\n");
=======

    // #    save the values in array
    char** values = getJsonValues(myJson);
    int i;
>>>>>>> 90d9987f42c9a517a1c424b91bb6cab784484b0f
    for(i = 0 ; i < myJson.size ; i++){
        fprintf(stdout,"Value: %s\n",values[i]);
    }
    free(values);
    return 0;
}
