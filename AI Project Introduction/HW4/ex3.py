# hw4 - Exercise3
# writer : 21700760 Juyoung Ha

import pandas as pd
import numpy as np
import nltk
from bs4 import BeautifulSoup
import string
import spacy
from nltk.corpus import stopwords

count = 1

# read data from csv file
reviewFile = pd.read_csv('amazon_train_df.csv', index_col='0')
# print(reviewFile)

# load one review sentence from csv file
reviewList = reviewFile.iloc[0:, 3] # load the review part
review = np.array(reviewList)

# Cleaning(punctuation, lowercase)
def remove_punctuation(text):
    sent = []
    for t in text.split(' '):
        no_punct = "".join([c for c in t if c not in string.punctuation])
        sent.append(no_punct)

    sentence = " ".join(s for s in sent)
    return sentence


for p in range(0, 5):
    # Cleaning(1) - punctuation
    rmv_punc_sentence = remove_punctuation(review[p])
    # Cleaning(2) - lower case
    lower_sentence = rmv_punc_sentence.lower()


    # Tokenization & Lemmatization
    # Load the installed model "en_core_web_sm" into "nlp"
    nlp = spacy.load('en_core_web_sm')

    ## 'doc' is a sequence of Token objects
    ## it holds all information about the tokens, their linguistic features and their relationships.
    doc = nlp(lower_sentence.strip())
    tok_lem_sentence = [token.lemma_ for token in doc]

    # Removing Stopwords
    stop_words = set(stopwords.words('english'))
    rmv_sw_sentence = [w for w in tok_lem_sentence if not w in stop_words]
    removed_word = [w for w in tok_lem_sentence if not w in rmv_sw_sentence]

    # Encoding(=> Integer Encoding)
    # make dictionary
    dictionary = {}

    def make_frequency_dict(text):
        for word in text:
            if word not in dictionary:
                dictionary[word] = 0
            dictionary[word] += 1

    make_frequency_dict(rmv_sw_sentence)
    vocab_sorted = sorted(dictionary.items(), key=lambda x: x[1], reverse=True)
    #print(vocab_sorted)

    tmpList = []
    for k in range(0, 5):
        tmpList.append(vocab_sorted[k])
    print("review%d : " % count, end='')
    for r in range(0, 5):
        if r<4:
            print(tmpList[r][0] + ", ", end='')
        else:
            print(tmpList[r][0])
    count += 1

'''
    # make a dictionary based on frequency
    word_to_index = {}
    i = 0
    #print(vocab_sorted)
    for (word, frequency) in vocab_sorted:
        if frequency > 1:
            i += 1
            word_to_index[word] = i
    #print(word_to_index)

    # Add OOV index for unknown words
    word_to_index['OOV'] = len(word_to_index) + 1
    # encoding the words
    encoded = []

    #print(rmv_sw_sentence)
    for w in rmv_sw_sentence:
        encoded.append(word_to_index.get(w, word_to_index['OOV']))
    #print(encoded)
'''