#include "c2wasm.c"
#include "LuaCEmbedOne.c"
#include <stdlib.h>


void insert_on_element_inner(c2wasm_js_var element, const char *value){
    c2wasm_js_var args = c2wasm_create_array();
    c2wasm_append_array_string(args, "beforeend");
    c2wasm_append_array_string(args, value);
    c2wasm_call_object_prop(element,"insertAdjacentHTML",args);
}

LuaCEmbedResponse *custom_print(LuaCEmbed *args){

    c2wasm_js_var id_output_view  = c2wasm_create_array();
    c2wasm_append_array_string(id_output_view, "outputView");
    c2wasm_js_var output_view_element = c2wasm_call_object_prop(c2wasm_document,"getElementById", id_output_view);
    
    long args_size = LuaCEmbed_get_total_args(args);
    for(long i = 0; i < args_size; i++){
        int type = LuaCEmbed_get_arg_type(args,i);
        if(type == LUA_CEMBED_NUMBER){
            double value = LuaCEmbed_get_double_arg(args,i);
            char msg[20];
            sprintf(msg,"%lf",value);
            insert_on_element_inner(output_view_element,msg);
            insert_on_element_inner(output_view_element," ");
        }
        else if(type == LUA_CEMBED_STRING){
            char *value = LuaCEmbed_get_str_arg(args,i);
            insert_on_element_inner(output_view_element,value);
            insert_on_element_inner(output_view_element," ");
        }
        else if(type == LUA_CEMBED_BOOL){
            int value = LuaCEmbed_get_bool_arg(args,i);
            if(value){
                insert_on_element_inner(output_view_element,"true");
            }else{
                insert_on_element_inner(output_view_element,"false");
            }
            insert_on_element_inner(output_view_element," ");
        }
        else if(type == LUA_CEMBED_NIL){
            insert_on_element_inner(output_view_element,"nil");
            insert_on_element_inner(output_view_element," ");
        }
        else if(type == LUA_CEMBED_FUNCTION){
            insert_on_element_inner(output_view_element,"function");
            insert_on_element_inner(output_view_element," ");
        }
        else  if(type == LUA_CEMBED_TABLE){
            insert_on_element_inner(output_view_element,"table");
            insert_on_element_inner(output_view_element," ");
        }
        else if(type == LUA_TUSERDATA){
            insert_on_element_inner(output_view_element,"userdata");
            insert_on_element_inner(output_view_element," ");
        }
        else{
            char msg[20];
            sprintf(msg,"unknown type %d",type);
            insert_on_element_inner(output_view_element,msg);
            insert_on_element_inner(output_view_element," ");
        }
        
        
    }
    insert_on_element_inner(output_view_element,"<br>");

   return NULL;
}

c2wasm_js_var execute_lua_machine(){

    c2wasm_js_var id_collect_args  = c2wasm_create_array();
    c2wasm_append_array_string(id_collect_args, "codeEditor");
    c2wasm_js_var text_area_element = c2wasm_call_object_prop(c2wasm_document,"getElementById", id_collect_args);

    long size = c2wasm_get_object_string_len_prop(text_area_element,"value");
    char *code_buffer = malloc(size+1);
    c2wams_object_memcpy_string(text_area_element,"value",0,code_buffer,size);
    code_buffer[size] = '\0';   

   
    c2wasm_js_var id_output_view  = c2wasm_create_array();
    c2wasm_append_array_string(id_output_view, "outputView");
    c2wasm_js_var output_view_element = c2wasm_call_object_prop(c2wasm_document,"getElementById", id_output_view);
    c2wasm_set_object_prop_string(output_view_element,"innerHTML","");


    LuaCEmbed *lua_virtual_machine = newLuaCEmbedEvaluation();
    LuaCEmbed_add_callback(lua_virtual_machine,"print",custom_print);
    LuaCEmbed_evaluate(lua_virtual_machine,code_buffer);
   
    if(LuaCEmbed_has_errors(lua_virtual_machine)){
        char *error_msg = LuaCEmbed_get_error_msg(lua_virtual_machine);
        c2wasm_set_object_prop_string(output_view_element,"innerHTML",error_msg);
    }
    

    LuaCEmbed_free(lua_virtual_machine);
    free(code_buffer);
    return c2wasm_undefined;
}

int main(){
    c2wasm_start();
    c2wasm_set_object_prop_function(c2wasm_window,"execute_lua_machine",execute_lua_machine);
    return 0;

}