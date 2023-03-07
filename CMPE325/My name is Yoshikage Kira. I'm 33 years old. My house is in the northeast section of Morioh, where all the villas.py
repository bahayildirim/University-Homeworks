from functools import reduce

def stem(word: str):
    return word.lower().rstrip(",.!:;'-\"").lstrip("'\"")
def read_file():
    with open("quote.txt", "r") as quote_f:
        quote = quote_f.read()
    return quote
def frequencies(list,word):
    freq_list = [*map(lambda a: 1 if a == word else 0,list)]
    if list[-1] == word:
        freq_list.append(1)
    else:
        freq_list.append(0)
    total_freq = reduce(lambda a,b: a+b,freq_list)
    print(total_freq)
def is_same_word(word):
    return 0
quote = read_file()
quote = quote.split()
quote = list(map(stem,quote))
print(quote)
frequencies(quote,"is")
 