#!/usr/bin/env ruby


#// The second value provided to the macro specifies the type of the function
#// (result value, then each argument) as follows:
#//  v -> void
#//  b -> boolean
#//  c -> char
#//  s -> short
#//  i -> int
#//  h -> half
#//  f -> float
#//  d -> double
#//  z -> size_t
#//  w -> wchar_t
#//  F -> constant CFString
#//  G -> id
#//  H -> SEL
#//  M -> struct objc_super
#//  a -> __builtin_va_list
#//  A -> "reference" to __builtin_va_list
#//  V -> Vector, followed by the number of elements and the base type.
#//  E -> ext_vector, followed by the number of elements and the base type.
#//  X -> _Complex, followed by the base type.
#//  Y -> ptrdiff_t
#//  P -> FILE
#//  J -> jmp_buf
#//  SJ -> sigjmp_buf
#//  K -> ucontext_t
#//  p -> pid_t
#//  . -> "...".  This may only occur at the end of the function list.
#//
#// Types may be prefixed with the following modifiers:
#//  L   -> long (e.g. Li for 'long int', Ld for 'long double')
#//  LL  -> long long (e.g. LLi for 'long long int', LLd for __float128)
#//  LLL -> __int128_t (e.g. LLLi)
#//  W   -> int64_t
#//  N   -> 'int' size if target is LP64, 'L' otherwise.
#//  S   -> signed
#//  U   -> unsigned
#//  I   -> Required to constant fold to an integer constant expression.
#//
#// Types may be postfixed with the following modifiers:
#// * -> pointer (optionally followed by an address space number, if no address
#//               space is specified than any address space will be accepted)
#// & -> reference (optionally followed by an address space number)
#// C -> const
#// D -> volatile

def split_the_first(str, keys)
    return "", "" if !str || str.length == 0
    keys.each{|entry|
        key = entry[0]
        val = entry[1]
        next if str.length < key.length
        if str.slice(0 .. key.length-1) == key
            return val, str.slice(key.length .. -1)
        end
        #if str =~ /^#{key}(.*)/
            #return val, $1
        #end
    }
    return "", str
end

def parse_type(str)
    prefix = [["LLL", "__int128_t"], ["LL", "long long"], ["L", "long"], ["S", "signed"], ["U", "unsigned"]]
    type = [
        #["E4f", "float __attribute__((ext_vector_type(4)))"], ["E2f", "float __attribute__((ext_vector_type(2)))"],
        #["E4d", "double __attribute__((ext_vector_type(4)))"], ["E2d", "double __attribute__((ext_vector_type(2)))"],
        #["E4c", "char __attribute__((ext_vector_type(4)))"], ["E2c", "char __attribute__((ext_vector_type(2)))"],
        #["E4s", "short __attribute__((ext_vector_type(4)))"], ["E2s", "short __attribute__((ext_vector_type(2)))"],
        #["E4i", "int __attribute__((ext_vector_type(4)))"], ["E2i", "int __attribute__((ext_vector_type(2)))"],
        #["E4LL", "long long __attribute__((ext_vector_type(4)))"], ["E2LL", "long long __attribute__((ext_vector_type(2)))"],
        #["E4Uc", "unsigned char __attribute__((ext_vector_type(4)))"], ["E2Uc", "unsigned char __attribute__((ext_vector_type(2)))"],
        #["E4Us", "unsigned short __attribute__((ext_vector_type(4)))"], ["E2Us", "unsigned short __attribute__((ext_vector_type(2)))"],
        #["E4Ui", "unsigned int __attribute__((ext_vector_type(4)))"], ["E2Ui", "unsigned int __attribute__((ext_vector_type(2)))"],
        #["E4ULL", "unsigned long long __attribute__((ext_vector_type(4)))"], ["E2ULL", "unsigned long long __attribute__((ext_vector_type(2)))"],
        ["E4f", "vfloat4"], ["E2f", "vfloat2"],
        ["E4d", "vdouble4"], ["E2d", "vdouble2"],
        ["E4c", "vchar4"], ["E2c", "vchar2"],
        ["E4s", "vshort4"], ["E2s", "vshort2"],
        ["E4i", "vint4"], ["E2i", "vint2"],
        ["E4LL", "vlonglong4"], ["E2LL", "vlonglong2"],
        ["E4Uc", "vunsignedchar4"], ["E2Uc", "vunsignedchar2"],
        ["E4Us", "vunsignedshort4"], ["E2Us", "vunsignedshort2"],
        ["E4Ui", "vunsignedint4"], ["E2Ui", "vunsignedint2"],
        ["E4ULL", "vunsignedlonglong4"], ["E2ULL", "vunsignedlonglong2"],
        ["V4f", "float4"], ["V4i", "int4"],
        ["W", "int64_t"], 
        ["v", "void"], ["b", "bool"], ["c", "char"], ["s", "short"], ["i", "int"], ['I', 'int'], ["h", "half"], ["f", "float"], ["d", "double"], ["z", "size_t"], ["w", "wchar_t"], ["G", "id"], ["Y", "ptrdiff_t"], ["p", "pid_t"]]
    suffix = [["C", "const"], ["D", "volatile"], ["*", "*"], ["0", ""], ["1", ""], ["2", ""], ["3", ""], ["4", ""], ["5", ""], ["6", ""], ["7", ""], ["8", ""],]
    #p, str = split_the_first(str, prefix)
    p = ""
    while true do
        p_tmp, str = split_the_first(str, prefix)
        break if p_tmp == ""
        p += " " + p_tmp
    end
    t, str = split_the_first(str, type)
    s = ""
    while true do
        s_tmp, str = split_the_first(str, suffix)
        break if s_tmp == ""
        s += " " + s_tmp
    end
    result = p
    result += " " if result != "" && t != ""
    result += t
    result += " " if result != "" && s != ""
    result += s
    return result, str
end

[2, 4].each{|vlen|
    ['float', 'double', 'char', 'short', 'int', 'long long', 'unsigned char', 'unsigned short', 'unsigned int', 'unsigned long long'].each{|type|
        print "typedef #{type} v#{type.gsub(' ', '')}#{vlen} __attribute__((ext_vector_type(#{vlen})));\n"
    }
}
print "typedef long int64_t;\n"
STDIN.each_line {|line|
    if line =~ /BUILTIN\((\S+), "(\S+)", "(\S*)"\)/ || line =~ /TARGET_BUILTIN\((\S+), "(\S+)", "(\S*)", .*\)/
        func = $1
        param = $2
        next if func =~ /^__builtin/
        #print "Checking #{line}\n"
        types = []
        while param && param != ""
            type, param = parse_type(param)
            types.push type
            #print "#{type}\n"
        end
        raise if types.size == 0
        print "__DEVICE__ #{types[0]} #{func}("
        1.upto(types.length - 1){|i|
            print types[i]
            print ", " if i < types.length - 1
        }
        print ");\n"

        #print "#{func} #{param}\n"
    end
}
