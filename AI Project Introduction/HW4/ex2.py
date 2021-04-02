# hw4 - Exercise2
# writer : 21700760 Juyoung Ha

#!/usr/bin/env python
# coding: utf-8

# ## Preprocessing

# In[17]:


import pandas as pd
import nltk
from bs4 import BeautifulSoup
import string
from nltk.corpus import stopwords

# ### 1. Read in csv file and create Dataframe & check shape.

# In[18]:


str_data = """<html><h2>What is nlp??? </h2></html> 
Natural Language Processing, or NLP for short, is broadly defined as the automatic manipulation of natural language, like speech and text, by software.
The study of natural language processing has been around for more than 50 years and grew out of the field of linguistics with the rise of computers.
(In this post), you will discover what natural language processing is and why it is so important.
After reading this post, you will know => What natural language is and how it is different from other types of data."""
str_data


# ### 2-1. Cleaning - Remove HTML

# In[51]:


def remove_html(text_data):
    soup = BeautifulSoup(text_data, 'lxml')
    return soup.get_text()


processed_text = remove_html(str_data)
print(processed_text)

# ### 2-2. Cleaning - Remove punctuation & Lower case

# In[1]:


## Check English's punctuation
print('Punctuation: ', string.punctuation)


# In[2]:


def remove_punctuation(text):
    sent = []
    for t in text.split(' '):
        no_punct = "".join([c for c in t if c not in string.punctuation])
        sent.append(no_punct)

    sentence = " ".join(s for s in sent)
    return sentence


# In[13]:


rmv_punc_sentence = remove_punctuation(processed_text)
print(rmv_punc_sentence)

# In[14]:


lower_sentence = rmv_punc_sentence.lower()
print(lower_sentence)

# ### 3. Lemmatization & Tokenization with spacy library

# In[8]:


## using "spacy" library
import spacy

## Load the installed model "en_core_web_sm" into "nlp"
nlp = spacy.load('en_core_web_sm')

# In[6]:


## 'doc' is a sequence of Token objects
## it holds all information about the tokens, their linguistic features and their relationships.
doc = nlp(lower_sentence.strip())

# In[9]:

tok_lem_sentence = [(token.text, token.lemma_) for token in doc]
tok_lem_sentence[:15]

# ### 4. Remove stop words

# In[10]:


from nltk.corpus import stopwords

print(stopwords.words('english')[:10])
print(len(stopwords.words('english')))

# In[15]:


from nltk.corpus import stopwords

stop_words = set(stopwords.words('english'))

print(tok_lem_sentence, '\n')
rmv_sw_sentence = [w for w in tok_lem_sentence if not w in stop_words]
print(rmv_sw_sentence)
removed_word = [w for w in tok_lem_sentence if not w in rmv_sw_sentence]
print("\nRemoved word: ", set(removed_word))

# ### 5. Make dictionary

# In[29]:


import numpy as np

dictionary = {}


def make_frequency_dict(text):
    for word in text:
        if word not in dictionary:
            dictionary[word] = 0
        dictionary[word] += 1


make_frequency_dict(rmv_sw_sentence)

# In[30]:


len(dictionary)

# In[16]:


dictionary

# In[17]:


vocab_sorted = sorted(dictionary.items(), key=lambda x: x[1], reverse=True)
vocab_sorted

# In[18]:


word_to_index = {}
i = 0

for (word, frequency) in vocab_sorted:
    if frequency > 1:
        i += 1
        word_to_index[word] = i
print(word_to_index)

# In[19]:


word_to_index['OOV'] = len(word_to_index) + 1
print(word_to_index)

# ### 6. Encoding

# In[20]:


encoded = []

print(rmv_sw_sentence)

for w in rmv_sw_sentence:
    encoded.append(word_to_index.get(w, word_to_index['OOV']))
print(encoded)

# ## THE END 🌟
