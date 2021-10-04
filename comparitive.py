import time
import random
import string

# generate random integer values
from random import seed
from random import randint
# seed random number generator
import pickle

def random_generate_string(size):
    letters = string.ascii_lowercase
    return ''.join(random.choice(letters) for i in range(size)) 

def generate_random(num):
    strings = []
    for _ in range(num):
        value = randint(0, 10000)
        strings.append(random_generate_string(value))
    return strings


# def random_generate_string_from_list(size,lists):
#     letters = lists
#     return ''.join(random.choice(letters) for i in range(size)) 


# def generate_random_from_list(num,lists):
#     strings = []
#     for _ in range(num):
#         value = randint(0, 10000)
#         strings.append(random_generate_string_from_list(value,lists))
#     return strings

def compress_lzw(string):
    start_time = time.time()
    maximum_table_size = pow(2,int(9))  
    dictionary = {chr(i):i for i in range(256)}
    last = 256
    p = ""
    result = []
    for c in string:
        pc = p+c
        if pc in dictionary:
            p = pc
        else:
            result.append(dictionary[p])
            if(len(dictionary) <= maximum_table_size):
                dictionary[pc] = last
                last += 1
            p = c
    if p != '':
        result.append(dictionary[p])
#     if p in dictionary:
#         compressed_data.append(dictionary[p])
        
    uncompressed_file_size = len(string)*8
    compressed_file_size = len(result)*9
    print("Time to Compress: %s sec" % (time.time() - start_time) )
    print("Uncompressed string size",uncompressed_file_size, 'bits')
    print("Compressed string size",compressed_file_size, 'bits')
    return result

def decompress_lzw(compressed_data):
    start_time = time.time()
    dictionary = dict([(x, chr(x)) for x in range(255)])
    next_code = 256
    decompressed_data = ""
    string = ""
    for code in compressed_data:
        if not (code in dictionary):
            dictionary[code] = string + (string[0])
        decompressed_data += dictionary[code]
        if not(len(string) == 0):
            dictionary[next_code] = string + (dictionary[code][0])
            next_code += 1
        string = dictionary[code]
    
    print("Time to Decompress: %s sec" % (time.time() - start_time) )
    
    return decompressed_data
    
    return decompressed_data

def compress_huff(input_string):
    start_time = time.time()
    letters = [] # freq of each letter format is freq,letter
    only_letters = [] #unique list of letters
    for letter in input_string:
        if letter not in letters:
            freq = input_string.count(letter)
            letters.append(freq)
            letters.append(letter)
            only_letters.append(letter)
            
    nodes = []
    while len(letters)>0:
        nodes.append(letters[0:2])
        letters = letters[2:]
    nodes.sort()
    huffman_tree = []
    huffman_tree.append(nodes) #base level nodes of tree
    
    def combine(nodes):
        pos = 0
        newnode = []
        if len(nodes)>1:
            nodes.sort()
            nodes[pos].append('0')
            nodes[pos+1].append('1')
            combine_node1 = (nodes[pos][0]+nodes[pos+1][0])
            combine_node2 = (nodes[pos][1]+nodes[pos+1][1])
            newnode.append(combine_node1)
            newnode.append(combine_node2)
            newnodes = []
            newnodes.append(newnode)
            newnodes = newnodes + nodes[2:]
            nodes = newnodes
            huffman_tree.append(nodes)
            combine(nodes)
        return huffman_tree
    
    newnodes = combine(nodes)
    huffman_tree.sort(reverse=True)

    checklist = []
    
    for level in huffman_tree:
        for node in level:
            if node not in checklist:
                checklist.append(node)
            else:
                level.remove(node)
    
    letter_binary = []
    if len(only_letters)==1:
        letter_code = [only_1etters[0],'0']
        letter_binary.append(letter_code*len(input_string))

    else:
        for letter in only_letters:

            lettercode = ''
            for node in checklist:
                if len(node)>2 and letter in node[1]:
                    lettercode = lettercode + node[2]
            letter_code = [letter,lettercode]
            letter_binary.append(letter_code)
            
    bitstring = ''
    for character in input_string:
        for item in letter_binary:
            if character in item:
                bitstring = bitstring + item[1]
                
    binary = bitstring
    
    uncompressed_file_size = len(input_string)*8
    compressed_file_size = len(binary)
    time_to_compress = (time.time() - start_time)
    print("Time to Compress: %s sec" % time_to_compress )
    #print(input_string)
    print("Uncompressed string size",uncompressed_file_size, 'bits')
    #print(binary)
    print("Compressed string size",compressed_file_size, 'bits')
    
    return binary,letter_binary

def decompress_huff(binary,letter_binary):
    start_time = time.time()
    #bitstring = str(binary[2:])
    bitstring=binary
    uncompressed_string = ''
    code = ''
    for digit in bitstring:
        code = code + digit
        pos = 0
        for letter in letter_binary:
            if code == letter[1]:
                uncompressed_string = uncompressed_string + letter_binary[pos][0]
                code = ''
            pos+=1
    print("Time to Decompress: %s sec" % (time.time() - start_time) )
    return uncompressed_string
strings = generate_random(50)
#strings_from_list = generate_random_from_list(50,'ab')

#strings = ['But I must explain to you how all this mistaken idea of denouncing pleasure and praising pain was born and I will give you a complete account of the system, and expound the actual teachings of the great explorer of the truth, the master-builder of human happiness. No one rejects, dislikes, or avoids pleasure itself, because it is pleasure, but because those who do not know how to pursue pleasure rationally encounter consequences that are extremely painful. Nor again is there anyone who loves or pursues or desires to obtain pain of itself, because it is pain, but because occasionally circumstances occur in which toil and pain can procure him some great pleasure. To take a trivial example, which of us ever undertakes laborious physical exercise, except to obtain some advantage from it? But who has any right to find fault with a man who chooses to enjoy a pleasure that has no annoying consequences, or one who avoids a pain that produces no resultant pleasure?']
for i in range(len(strings)):
    print('\n#### String',i+1,'####\n')
    print("####LZW CODING####\n")
    compressed_data = compress_lzw(strings[i])
    decompress_lzw(compressed_data)
    print("\n####Huffman CODING####\n")
    binary,letter_binary = compress_huff(strings[i])
    decompress_huff(binary,letter_binary)

# for i in range(len(strings_from_list)):
#     print('\n#### String',i+1,'####\n')
#     #print(strings_from_list[i])
#     print("####LZW CODING####\n")
#     compressed_data = compress_lzw(strings_from_list[i])
#     decompress_lzw(compressed_data)
#     print("\n####Huffman CODING####\n")
#     binary,letter_binary = compress_huff(strings_from_list[i])
#     decompress_huff(binary,letter_binary)


