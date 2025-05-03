
/*
  ______    ______   __       __                                   
 /      \  /      \ /  |  _  /  |                                  
/$$$$$$  |/$$$$$$  |$$ | / \ $$ |  ______    _______  _____  ____  
$$ |  $$/ $$____$$ |$$ |/$  \$$ | /      \  /       |/     \/    \ 
$$ |       /    $$/ $$ /$$$  $$ | $$$$$$  |/$$$$$$$/ $$$$$$ $$$$  |
$$ |   __ /$$$$$$/  $$ $$/$$ $$ | /    $$ |$$      \ $$ | $$ | $$ |
$$ \__/  |$$ |_____ $$$$/  $$$$ |/$$$$$$$ | $$$$$$  |$$ | $$ | $$ |
$$    $$/ $$       |$$$/    $$$ |$$    $$ |/     $$/ $$ | $$ | $$ |
 $$$$$$/  $$$$$$$$/ $$/      $$/  $$$$$$$/ $$$$$$$/  $$/  $$/  $$/ 
                                                                   
                                                                   
                                                                   
*/

/*
MIT License

Copyright (c) 2025 OUI

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/


#ifndef c2wasm_macro
#define c2wasm_macro


#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#ifndef EMSCRIPTEN_KEEPALIVE
#define EMSCRIPTEN_KEEPALIVE
#endif

#ifndef EM_JS
#define EM_JS(ret, name, params, body) ret name params;
#endif
#ifndef true 
#define true 1
#endif
#ifndef false
#define false 0
#endif




#define c2wasm_false 0
#define c2wasm_true 1
#define c2wasm_null 2
#define c2wasm_undefined 3
#define c2wasm_arguments 4
#define c2wasm_window 5
#define c2wasm_document 6
#define c2wasm_body 7

typedef long c2wasm_js_var;

#define C2WASM_UNDEFINED_TYPE 0
#define C2WASM_NULL_TYPE 1
#define C2WASM_BOOLEAN_TYPE 2
#define C2WASM_NUMBER_TYPE 3
#define C2WASM_STRING_TYPE 4
#define C2WASM_OBJECT_TYPE 5
#define C2WASM_ARRAY_TYPE 6
#define C2WASM_FUNCTION_TYPE 7
#define C2WASM_SYMBOL_TYPE 8
#define C2WASM_BIGINT_TYPE 9

#endif

#ifndef c2wasm_em_js
#define c2wasm_em_js






/*
  ______                                                                  __ 
 /      \                                                                /  |
/$$$$$$  |         ______    ______    ______    ______   _______    ____$$ |
$$ |__$$ | ______ /      \  /      \  /      \  /      \ /       \  /    $$ |
$$    $$ |/      |$$$$$$  |/$$$$$$  |/$$$$$$  |/$$$$$$  |$$$$$$$  |/$$$$$$$ |
$$$$$$$$ |$$$$$$/ /    $$ |$$ |  $$ |$$ |  $$ |$$    $$ |$$ |  $$ |$$ |  $$ |
$$ |  $$ |       /$$$$$$$ |$$ |__$$ |$$ |__$$ |$$$$$$$$/ $$ |  $$ |$$ \__$$ |
$$ |  $$ |       $$    $$ |$$    $$/ $$    $$/ $$       |$$ |  $$ |$$    $$ |
$$/   $$/         $$$$$$$/ $$$$$$$/  $$$$$$$/   $$$$$$$/ $$/   $$/  $$$$$$$/ 
                           $$ |      $$ |                                    
                           $$ |      $$ |                                    
                           $$/       $$/                                     
*/
EM_JS(void, c2wasm_append_array_long, (c2wasm_js_var stack_index, long value), {
    let array = window.c2wasm_stack[stack_index];
    array.push(value);
});

EM_JS(void, c2wasm_append_array_double, (c2wasm_js_var stack_index, double value), {
    let array = window.c2wasm_stack[stack_index];
    array.push(value);
});

EM_JS(void, c2wasm_append_array_string, (c2wasm_js_var stack_index, const char *value), {
    let array = window.c2wasm_stack[stack_index];
    array.push(window.c2wasm_get_string(value));
});

EM_JS(void, c2wasm_append_array_any, (c2wasm_js_var stack_index, c2wasm_js_var stack_index_value), {
    let array = window.c2wasm_stack[stack_index];
    array.push(window.c2wasm_stack[stack_index_value]);
});

EM_JS(void, c2wasm_append_array_bool, (c2wasm_js_var stack_index, int value), {
    let array = window.c2wasm_stack[stack_index];
    array.push(value ? true : false);
});








/*
  ______                                 __     
 /      \                               /  |    
/$$$$$$  |          ______    ______   _$$ |_   
$$ |__$$ | ______  /      \  /      \ / $$   |  
$$    $$ |/      |/$$$$$$  |/$$$$$$  |$$$$$$/   
$$$$$$$$ |$$$$$$/ $$ |  $$ |$$    $$ |  $$ | __ 
$$ |  $$ |        $$ \__$$ |$$$$$$$$/   $$ |/  |
$$ |  $$ |        $$    $$ |$$       |  $$  $$/ 
$$/   $$/          $$$$$$$ | $$$$$$$/    $$$$/  
                  /  \__$$ |                    
                  $$    $$/                     
                   $$$$$$/                      
*/

EM_JS(long ,c2wasm_get_array_size,(long stack_index), {
    let array = window.c2wasm_stack[stack_index];
    return array.length;
});
EM_JS(long ,c2wasm_get_array_long_by_index,(long stack_index, int index), {
    let array = window.c2wasm_stack[stack_index];
    return array[index];
});

EM_JS(double ,c2wasm_get_array_double_by_index,(long stack_index, int index,char *dest,int size), {
    let array = window.c2wasm_stack[stack_index];
    return array[index];
});

EM_JS(int ,c2wasm_get_array_string_size_by_index,(long stack_index, int index), {
    let array = window.c2wasm_stack[stack_index];
    let value = array[index];
    return value.length;
});


EM_JS(void* ,c2wasm_array_memcpy_string,(long stack_index, int index,int string_index, char *dest, int size), {
    let array = window.c2wasm_stack[stack_index];
    let value = array[index];
    for(let i = 0; i < size; i++){
      
        let current_char = value.charCodeAt(i+start_string);
        if(isNaN(current_char)){
            break;
        }
        wasmExports.c2wasm_set_char(dest,i,current_char);
    }
    return dest;
});


EM_JS(c2wasm_js_var ,c2wasm_get_array_any_by_index,(long stack_index, int index), {
    let array = window.c2wasm_stack[stack_index];

    let value = array[index];
    if(value == false){
        return  window.c2wasm_false;
    }
    if(value == true){
        return window.c2wasm_true;
    }
    if(value == null){
        return window.c2wasm_null;
    }
    if(value == undefined){
        return window.c2wasm_undefined;
    }
    let created_index = window.c2wasm_get_stack_point();
    window.c2wasm_stack[created_index] = value;
    return created_index;
});
EM_JS(int ,c2wasm_get_array_type_by_index,(long stack_index, int index),{
    let array = window.c2wasm_stack[stack_index];
    let value = array[index];
    return window.c2wasm_get_type(value);
});


EM_JS(int ,c2wasm_get_array_bool_by_index,(long stack_index, int index),{
    let array = window.c2wasm_stack[stack_index];
    let value = array[index];
    if(value == false){
        return 0;
    }
    return 1;
});










/*
  ______           __                                            __     
 /      \         /  |                                          /  |    
/$$$$$$  |        $$/  _______    _______   ______    ______   _$$ |_   
$$ |__$$ | ______ /  |/       \  /       | /      \  /      \ / $$   |  
$$    $$ |/      |$$ |$$$$$$$  |/$$$$$$$/ /$$$$$$  |/$$$$$$  |$$$$$$/   
$$$$$$$$ |$$$$$$/ $$ |$$ |  $$ |$$      \ $$    $$ |$$ |  $$/   $$ | __ 
$$ |  $$ |        $$ |$$ |  $$ | $$$$$$  |$$$$$$$$/ $$ |        $$ |/  |
$$ |  $$ |        $$ |$$ |  $$ |/     $$/ $$       |$$ |        $$  $$/ 
$$/   $$/         $$/ $$/   $$/ $$$$$$$/   $$$$$$$/ $$/          $$$$/  
*/
EM_JS(void, c2wasm_insert_array_long_by_index, (c2wasm_js_var stack_index, int index, long value), {
    let array = window.c2wasm_stack[stack_index];
    array.splice(index, 0, value);
});

EM_JS(void, c2wasm_insert_array_double_by_index, (c2wasm_js_var stack_index, int index, double value), {
    let array = window.c2wasm_stack[stack_index];
    array.splice(index, 0, value);
});

EM_JS(void, c2wasm_insert_array_string_by_index, (c2wasm_js_var stack_index, int index, const char *value), {
    let array = window.c2wasm_stack[stack_index];
    array.splice(index, 0, window.c2wasm_get_string(value));
});

EM_JS(void, c2wasm_insert_array_any_by_index, (c2wasm_js_var stack_index, int index, c2wasm_js_var stack_index_value), {
    let array = window.c2wasm_stack[stack_index];
    array.splice(index, 0, window.c2wasm_stack[stack_index_value]);
});

EM_JS(void, c2wasm_insert_array_bool_by_index, (c2wasm_js_var stack_index, int index, int value), {
    let array = window.c2wasm_stack[stack_index];
    array.splice(index, 0, value ? true : false);
});








/*
  ______                                 __     
 /      \                               /  |    
/$$$$$$  |          _______   ______   _$$ |_   
$$ |__$$ | ______  /       | /      \ / $$   |  
$$    $$ |/      |/$$$$$$$/ /$$$$$$  |$$$$$$/   
$$$$$$$$ |$$$$$$/ $$      \ $$    $$ |  $$ | __ 
$$ |  $$ |         $$$$$$  |$$$$$$$$/   $$ |/  |
$$ |  $$ |        /     $$/ $$       |  $$  $$/ 
$$/   $$/         $$$$$$$/   $$$$$$$/    $$$$/  
*/

EM_JS(void,c2wasm_pop_array_by_index,(c2wasm_js_var stack_index, int index), {
    let array = window.c2wasm_stack[stack_index];
    array.splice(index, 1);
});

EM_JS(void ,c2wasm_set_array_long_by_index,(c2wasm_js_var stack_index, int index, long value), {
    let array = window.c2wasm_stack[stack_index];
    array[index] = value;
});

EM_JS(void ,c2wasm_set_array_double_by_index,(c2wasm_js_var stack_index, int index, double value), {
    let array = window.c2wasm_stack[stack_index];
    array[index] = value;
});

EM_JS(void ,c2wasm_set_array_string_by_index,(c2wasm_js_var stack_index, int index, const char *value), {
    let array = window.c2wasm_stack[stack_index];
    array[index] = window.c2wasm_get_string(value);
});

EM_JS(void ,c2wasm_set_array_any_by_index,( c2wasm_js_var stack_index, int index, int stack_index_value),{
    let array = window.c2wasm_stack[stack_index];
    array[index] = window.c2wasm_stack[stack_index_value];
})

EM_JS(void ,c2wasm_set_array_bool_by_index,(    c2wasm_js_var stack_index, int index, int value), {
    let array = window.c2wasm_stack[stack_index];
    if (value == 0){
        array[index] = false;
    }
    if (value > 0){
        array[index] = true;
    }
});

EM_JS(void ,c2wasm_set_array_null_by_index,(c2wasm_js_var stack_index, int index), {
    let array = window.c2wasm_stack[stack_index];
    array[index] = null;
});

EM_JS(void ,c2wasm_set_array_undefined_by_index,(c2wasm_js_var stack_index, int index), {
    let array = window.c2wasm_stack[stack_index];
    array[index] = undefined;
});









/*    _____   ______            ______                                   __      __                     
   /     | /      \          /      \                                 /  |    /  |                    
   $$$$$ |/$$$$$$  |        /$$$$$$  |  ______    ______    ______   _$$ |_   $$/   ______   _______  
      $$ |$$ \__$$/  ______ $$ |  $$/  /      \  /      \  /      \ / $$   |  /  | /      \ /       \ 
 __   $$ |$$      \ /      |$$ |      /$$$$$$  |/$$$$$$  | $$$$$$  |$$$$$$/   $$ |/$$$$$$  |$$$$$$$  |
/  |  $$ | $$$$$$  |$$$$$$/ $$ |   __ $$ |  $$/ $$    $$ | /    $$ |  $$ | __ $$ |$$ |  $$ |$$ |  $$ |
$$ \__$$ |/  \__$$ |        $$ \__/  |$$ |      $$$$$$$$/ /$$$$$$$ |  $$ |/  |$$ |$$ \__$$ |$$ |  $$ |
$$    $$/ $$    $$/         $$    $$/ $$ |      $$       |$$    $$ |  $$  $$/ $$ |$$    $$/ $$ |  $$ |
 $$$$$$/   $$$$$$/           $$$$$$/  $$/        $$$$$$$/  $$$$$$$/    $$$$/  $$/  $$$$$$/  $$/   $$/ 
                                                                                                      
*/

EM_JS(c2wasm_js_var,c2wasm_create_bool,(int value),{
    let index = window.c2wasm_get_stack_point();
    if (value == 0){
        window.c2wasm_stack[index] = false;
    }
    if (value > 0){
        window.c2wasm_stack[index] = true;
    }
    return index;
});

EM_JS(c2wasm_js_var,c2wasm_create_long,(long value),{
    let index = window.c2wasm_get_stack_point();
    window.c2wasm_stack[index] = value;
    return index;
});

EM_JS(c2wasm_js_var,c2wasm_create_double,(double value),{
    let index = window.c2wasm_get_stack_point();
    window.c2wasm_stack[index] = value;
    return index;
});

EM_JS(c2wasm_js_var,c2wasm_create_object,(void),{
    let index = window.c2wasm_get_stack_point();
    window.c2wasm_stack[index] = {};
    return index;
});

EM_JS(c2wasm_js_var,c2wasm_create_array,(void),{
    let index = window.c2wasm_get_stack_point();
    window.c2wasm_stack[index] = [];
    return index;
});

EM_JS(c2wasm_js_var,c2wasm_create_string,(const char *value),{
    let index = window.c2wasm_get_stack_point();
    window.c2wasm_stack[index] = window.c2wasm_get_string(value);
    return index;
});

EM_JS(c2wasm_js_var,c2wasm_create_function_with_internal_argsraw,(c2wasm_js_var internal_args, void *callback),{
    let internal_value = window.c2wasm_stack[internal_args];
    let index = window.c2wasm_get_stack_point();
    window.c2wasm_stack[index] =  window.c2wasm_create_js_c_interop_callback_with_internal_arg(callback,internal_value);
    return index;
});


EM_JS(c2wasm_js_var,c2wasm_create_function_raw,(void *callback),{
    let index = window.c2wasm_get_stack_point();
    window.c2wasm_stack[index] = window.c2wasm_create_js_c_interop_callback(callback);
    return index;
});









EM_JS(long ,c2wasm_get_string_len, (c2wasm_js_var string_index), {
    return window.c2wasm_stack[string_index].length;
});

EM_JS(void *,c2wasm_memcpy_string,(c2wasm_js_var stack_index,int start_string, char *dest, int size), {
    let value = window.c2wasm_stack[stack_index];
    for(let i = 0; i < size; i++){
      
        let current_char = value.charCodeAt(i+start_string);
        if(isNaN(current_char)){
            break;
        }
        wasmExports.c2wasm_set_char(dest,i,current_char);
    }
    return dest;
});







EM_JS(void,c2wasm_free,(long stack_index),{
    if(window.c2wasm_stack.length <= stack_index){
        return;
    }
    if(window.c2wasm_local_stack){
        //itremove the stack index from old_created obj
        let index_of_stack = window.c2wasm_local_stack.indexOf(stack_index);
        window.c2wasm_local_stack.splice(index_of_stack, 1);
    }
    delete window.c2wasm_stack[stack_index];
});








/*
    _____                               __                            __     
   /     |                             /  |                          /  |    
   $$$$$ |  _______          _______  _$$ |_     ______    ______   _$$ |_   
      $$ | /       |______  /       |/ $$   |   /      \  /      \ / $$   |  
 __   $$ |/$$$$$$$//      |/$$$$$$$/ $$$$$$/    $$$$$$  |/$$$$$$  |$$$$$$/   
/  |  $$ |$$      \$$$$$$/ $$      \   $$ | __  /    $$ |$$ |  $$/   $$ | __ 
$$ \__$$ | $$$$$$  |        $$$$$$  |  $$ |/  |/$$$$$$$ |$$ |        $$ |/  |
$$    $$/ /     $$/        /     $$/   $$  $$/ $$    $$ |$$ |        $$  $$/ 
 $$$$$$/  $$$$$$$/         $$$$$$$/     $$$$/   $$$$$$$/ $$/          $$$$/  
 
*/

EM_JS(void ,c2wasm_start, (void), {
    
    if (window.c2wasm_started){
        return;
    }

    
    window.c2wasm_started = true;


    window.c2wasm_false = 0;
    window.c2wasm_true = 1;
    window.c2wasm_null = 2;
    window.c2wasm_undefined = 3;


    window.c2wasm_stack = [];
    window.c2wasm_stack[0] = false;
    window.c2wasm_stack[1] = true;
    window.c2wasm_stack[2] = null;
    window.c2wasm_stack[3] = undefined;
    window.c2wasm_stack[4] = arguments;
    window.c2wasm_stack[5] = window;
    window.c2wasm_stack[6] = document;
    window.c2wasm_stack[7] = document.body;


    window.c2wasm_get_string = function(c_str ){
        let str_array  = [];
        let index = 0;
        while (true){
        let current_char = wasmExports.c2wasm_get_char(c_str,index);
        if (current_char == 0){
            break;
        }
        str_array[index] = current_char; 
        index++;
        }
        return String.fromCharCode.apply(null, str_array);
    };
    
    window.c2wasm_get_stack_point = function(){
        for(let i= 8; i < window.c2wasm_stack.length; i++){
            if (window.c2wasm_stack[i] == undefined){
                if(window.c2wasm_local_stack){
                    window.c2wasm_local_stack.push(i);
                }
                window.c2wasm_stack[i] = 0;
                return i;
            }
        }
        window.c2wasm_stack.push(0);
        let created_index = window.c2wasm_stack.length - 1;
        if(window.c2wasm_local_stack){
            window.c2wasm_local_stack.push(created_index);
        }
        return created_index;
    };
    window.c2wasm_create_js_c_interop_callback_with_internal_arg = function(callback,internal_value){
        return function(){
            let ARGUMENTS_STACK_INDEX = 4;
            let old_arguments = window.c2wasm_stack[ARGUMENTS_STACK_INDEX];
            window.c2wasm_stack[ARGUMENTS_STACK_INDEX] = arguments;
  
            let old_local_stack = window.c2wasm_local_stack;
            let current_local_stack = [];
            window.c2wasm_local_stack = current_local_stack;
            


            let new_interal_args_index = window.c2wasm_get_stack_point();
            window.c2wasm_stack[new_interal_args_index] = internal_value;
            
            let return_index = wasmExports.c2wasm_call_c_function_with_internal_args(new_interal_args_index,callback);
            let return_value = window.c2wasm_stack[return_index];
            
            for(let i = 0; i < current_local_stack.length; i++){
              let item_to_remove_from_stack = current_local_stack[i];
              delete window.c2wasm_stack[item_to_remove_from_stack];
            }
           
            window.c2wasm_stack[ARGUMENTS_STACK_INDEX] = old_arguments;
            window.c2wasm_local_stack = old_local_stack;

            if (return_value instanceof Error){
                throw return_value;
            }
            return return_value;
        };
    };
    window.c2wasm_create_js_c_interop_callback = function(callback){        

        return function(){
            let ARGUMENTS_STACK_INDEX = 4;
            let old_arguments = window.c2wasm_stack[ARGUMENTS_STACK_INDEX];
            window.c2wasm_stack[ARGUMENTS_STACK_INDEX] = arguments;
  
            let old_local_stack = window.c2wasm_local_stack;
            let current_local_stack = [];
            window.c2wasm_local_stack = current_local_stack;
        
            let return_index = wasmExports.c2wasm_call_c_function(callback);
            let return_value = window.c2wasm_stack[return_index];
            
            for(let i = 0; i < current_local_stack.length; i++){
              let item_to_remove_from_stack = current_local_stack[i];
              delete window.c2wasm_stack[item_to_remove_from_stack];
            }
           
            window.c2wasm_stack[ARGUMENTS_STACK_INDEX] = old_arguments;
            window.c2wasm_local_stack = old_local_stack;

            if( return_value instanceof Error){
                throw return_value;
            }
            return return_value;
        };
    };
    //check macro.types.h to see the types 
    window.c2wasm_get_type = function(value){
        if(value == undefined){
            return 0;
        };
        if(value == null){
            return 1;
        };
        if(value == true || value == false){
            return 2;
        };
        if(typeof value == "number"){
            return 3;
        };
        if(typeof value == "string"){
            return 4;
        };
        if(Array.isArray(value)){
            return 6;
        };
        if(typeof value == "object"){
            return 5;
        };
        if(typeof value == "function"){
            return 7;
        };
        if(typeof value == "symbol"){
            return 8;
        }
        if(typeof value == "bigint"){
            return 9;
        };
        return -1;
    };
});








/*
  ______                                 __     
 /      \                               /  |    
/$$$$$$  |          ______    ______   _$$ |_   
$$ |  $$ | ______  /      \  /      \ / $$   |  
$$ |  $$ |/      |/$$$$$$  |/$$$$$$  |$$$$$$/   
$$ |  $$ |$$$$$$/ $$ |  $$ |$$    $$ |  $$ | __ 
$$ \__$$ |        $$ \__$$ |$$$$$$$$/   $$ |/  |
$$    $$/         $$    $$ |$$       |  $$  $$/ 
 $$$$$$/           $$$$$$$ | $$$$$$$/    $$$$/  
                  /  \__$$ |                    
                  $$    $$/                     
                   $$$$$$/                      

*/

EM_JS(long ,c2wasm_get_object_prop_long,(c2wasm_js_var stack_index, const char *prop_name), {
    let object = window.c2wasm_stack[stack_index];
    let prop_name_formatted = window.c2wasm_get_string(prop_name);
    return object[prop_name_formatted];
});


EM_JS(int ,c2wasm_get_object_string_len_prop,(c2wasm_js_var stack_index, const char *prop_name), {
    let object = window.c2wasm_stack[stack_index];
    let prop_name_formatted = window.c2wasm_get_string(prop_name);
    let value = object[prop_name_formatted];
    return value.length;
});


EM_JS(void *,c2wams_object_memcpy_string,(c2wasm_js_var stack_index, const char *prop_name, int start_string, char *dest, int size), {
    let object = window.c2wasm_stack[stack_index];
    let prop_name_formatted = window.c2wasm_get_string(prop_name);
    let value = object[prop_name_formatted];
    for(let i = 0; i < size; i++){
        let current_char = value.charCodeAt(i+start_string);
        if(isNaN(current_char)){
            break;
        }
        wasmExports.c2wasm_set_char(dest,i,current_char);
    }
    return dest;
});


EM_JS(double ,c2wasm_get_object_prop_double,(c2wasm_js_var stack_index, const char *prop_name), {
    let object = window.c2wasm_stack[stack_index];
    let prop_name_formatted = window.c2wasm_get_string(prop_name);
    return object[prop_name_formatted];
});

EM_JS(int ,c2wasm_get_object_prop_type,(c2wasm_js_var stack_index, const char *prop_name),{
    let object = window.c2wasm_stack[stack_index];
    let prop_name_formatted = window.c2wasm_get_string(prop_name);
    let value = object[prop_name_formatted];
    return window.c2wasm_get_type(value);
});

EM_JS(int ,c2wasm_get_object_prop_bool,(c2wasm_js_var stack_index, const char *prop_name),{
    let object = window.c2wasm_stack[stack_index];
    let prop_name_formatted = window.c2wasm_get_string(prop_name);
    let value = object[prop_name_formatted];
    if(value == false){
        return 0;
    }

    return 1;

});

EM_JS(c2wasm_js_var , c2wasm_get_object_prop_any,(c2wasm_js_var stack_index, const char *prop_name),{
    let object = window.c2wasm_stack[stack_index];

    let prop_name_formatted = window.c2wasm_get_string(prop_name);
    let value  = object[prop_name_formatted];
    if(value == false){
        return  window.c2wasm_false;
    }
    if(value == true){
        return window.c2wasm_true;
    }
    if(value == null){
        return window.c2wasm_null;
    }
    if(value == undefined){
        return window.c2wasm_undefined;
    }

    let created_index = window.c2wasm_get_stack_point();
    window.c2wasm_stack[created_index] = value;
    return created_index;
    
});


EM_JS(c2wasm_js_var,c2wasm_call_object_prop,(c2wasm_js_var stack_index, const char *prop_name,c2wasm_js_var args),{
    let object = window.c2wasm_stack[stack_index];
    let prop_name_formatted = window.c2wasm_get_string(prop_name);
    let arguments = undefined;
    if(args != -1){
        arguments = window.c2wasm_stack[args];
    }
    let result = object[prop_name_formatted](...arguments);
    if(result == false){
        return  window.c2wasm_false;
    }
    if(result == true){
        return window.c2wasm_true;
    }
    if(result == null){
        return window.c2wasm_null;
    }
    if(result == undefined){
        return window.c2wasm_undefined;
    }
    let created_index = window.c2wasm_get_stack_point();
    window.c2wasm_stack[created_index] = result;
    return created_index;
});








/*
  ______                                 __     
 /      \                               /  |    
/$$$$$$  |          _______   ______   _$$ |_   
$$ |  $$ | ______  /       | /      \ / $$   |  
$$ |  $$ |/      |/$$$$$$$/ /$$$$$$  |$$$$$$/   
$$ |  $$ |$$$$$$/ $$      \ $$    $$ |  $$ | __ 
$$ \__$$ |         $$$$$$  |$$$$$$$$/   $$ |/  |
$$    $$/         /     $$/ $$       |  $$  $$/ 
 $$$$$$/          $$$$$$$/   $$$$$$$/    $$$$/  
                                                
                                            
*/

EM_JS(void,c2wasm_delete_object_prop,(c2wasm_js_var stack_index, const char *prop_name), {
    let object = window.c2wasm_stack[stack_index];
    let prop_name_formatted = window.c2wasm_get_string(prop_name);
    delete object[prop_name_formatted];
});

EM_JS(void ,c2wasm_set_object_prop_long,(long stack_index, const char *prop_name, long value), {
    let object = window.c2wasm_stack[stack_index];
    let prop_name_formatted = window.c2wasm_get_string(prop_name);
    object[prop_name_formatted] = value;
});

EM_JS(void ,c2wasm_set_object_prop_double,(long stack_index, const char *prop_name, float value), {
    let object = window.c2wasm_stack[stack_index];
    let prop_name_formatted = window.c2wasm_get_string(prop_name);
    object[prop_name_formatted] = value;
});

EM_JS(void ,c2wasm_set_object_prop_string,(long stack_index, const char *prop_name, const char *value), {
    let object = window.c2wasm_stack[stack_index];
    let prop_name_formatted = window.c2wasm_get_string(prop_name);
    let value_formatted = window.c2wasm_get_string(value);
    object[prop_name_formatted] = value_formatted;
});

EM_JS(void ,c2wasm_set_object_prop_bool,(c2wasm_js_var stack_index, const char *prop_name, int value), {
    let object = window.c2wasm_stack[stack_index];
    let prop_name_formatted = window.c2wasm_get_string(prop_name);
    if (value == 0){
        object[prop_name_formatted] = false;
    }
    if (value > 0){
        object[prop_name_formatted] = true;
    }
});

EM_JS(void ,c2wasm_set_object_prop_null,(c2wasm_js_var stack_index, const char *prop_name), {
    let object = window.c2wasm_stack[stack_index];
    let prop_name_formatted = window.c2wasm_get_string(prop_name);
    object[prop_name_formatted] = null;
});

EM_JS(void ,c2wasm_set_object_prop_undefined,(c2wasm_js_var stack_index, const char *prop_name), {
    let object = window.c2wasm_stack[stack_index];
    let prop_name_formatted = window.c2wasm_get_string(prop_name);
    object[prop_name_formatted] = undefined;
});

EM_JS(void,c2wasm_set_object_prop_any,(c2wasm_js_var stack_index, const char *prop_name, int stack_index_value),{
    let object = window.c2wasm_stack[stack_index];
    let prop_name_formatted = window.c2wasm_get_string(prop_name);
    object[prop_name_formatted] = window.c2wasm_stack[stack_index_value];
})


EM_JS(void ,private_c2wasm_set_object_prop_function_with_internal_args_raw,(c2wasm_js_var stack_index, const char *prop_name,c2wasm_js_var internal_args, void *callback),{
    let prop_name_formatted = window.c2wasm_get_string(prop_name);
    let object = window.c2wasm_stack[stack_index];
    let internal_value = window.c2wasm_stack[internal_args];
    object[prop_name_formatted] = window.c2wasm_create_js_c_interop_callback_with_internal_arg(callback,internal_value);
});


EM_JS(void ,private_c2wasm_set_object_prop_function_raw,(c2wasm_js_var stack_index, const char *prop_name, void *callback),{
      let prop_name_formatted = window.c2wasm_get_string(prop_name);
      let object = window.c2wasm_stack[stack_index];
      object[prop_name_formatted] = window.c2wasm_create_js_c_interop_callback(callback);
})

#endif

#ifndef c2wasm_fdefine
#define c2wasm_fdefine








c2wasm_js_var   c2wasm_create_function_with_internal_args(c2wasm_js_var internal_args,  c2wasm_js_var (*callback)(c2wasm_js_var internal_args)) {
    return c2wasm_create_function_with_internal_argsraw(internal_args, callback);
}

c2wasm_js_var   c2wasm_create_function(c2wasm_js_var (*callback)()) {
    return c2wasm_create_function_raw(callback);
}











EMSCRIPTEN_KEEPALIVE char c2wasm_get_char(const char *str,int index) {
    return str[index];
}
EMSCRIPTEN_KEEPALIVE void c2wasm_set_char(char *str,int index,char value) {
    str[index] = value;
}








EMSCRIPTEN_KEEPALIVE long c2wasm_call_c_function_with_internal_args(c2wasm_js_var internal_args,void *callback){
    long (*converted_callback)(long internal_args) = (long (*)(long))callback;
    return converted_callback(internal_args);
}

EMSCRIPTEN_KEEPALIVE long c2wasm_call_c_function(void *callback){
    long (*converted_callback)() = (long (*)())callback;
    return converted_callback();
}







EMSCRIPTEN_KEEPALIVE void c2wasm_set_object_prop_function_with_internal_args(c2wasm_js_var stack_index, const char *prop_name, c2wasm_js_var internal_args, c2wasm_js_var (*callback)(c2wasm_js_var internal_args)){
    private_c2wasm_set_object_prop_function_with_internal_args_raw(stack_index,prop_name,internal_args,callback);
}

EMSCRIPTEN_KEEPALIVE void c2wasm_set_object_prop_function( c2wasm_js_var stack_index, const char *prop_name, c2wasm_js_var (*callback)()){
    private_c2wasm_set_object_prop_function_raw(stack_index,prop_name,callback);
}
#endif



/*
MIT License

Copyright (c) 2025 OUI

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

/*
  ______    ______   __       __                                   
 /      \  /      \ /  |  _  /  |                                  
/$$$$$$  |/$$$$$$  |$$ | / \ $$ |  ______    _______  _____  ____  
$$ |  $$/ $$____$$ |$$ |/$  \$$ | /      \  /       |/     \/    \ 
$$ |       /    $$/ $$ /$$$  $$ | $$$$$$  |/$$$$$$$/ $$$$$$ $$$$  |
$$ |   __ /$$$$$$/  $$ $$/$$ $$ | /    $$ |$$      \ $$ | $$ | $$ |
$$ \__/  |$$ |_____ $$$$/  $$$$ |/$$$$$$$ | $$$$$$  |$$ | $$ | $$ |
$$    $$/ $$       |$$$/    $$$ |$$    $$ |/     $$/ $$ | $$ | $$ |
 $$$$$$/  $$$$$$$$/ $$/      $$/  $$$$$$$/ $$$$$$$/  $$/  $$/  $$/ 
                                                                   
                                                                   
                                                                   
*/