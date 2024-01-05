import matplotlib.pyplot
from wordcloud import WordCloud

words = open("lista.txt").read()

word_cloud = WordCloud(
  background_color = "white",
  width = 400,
  height = 300,
).generate(words)

matplotlib.pyplot.imshow(word_cloud, interpolation='bilinear')
matplotlib.pyplot.axis("off")
matplotlib.pyplot.show()
