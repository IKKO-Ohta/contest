import re

class Triplet:
	"""docstring for ClassName"""
	def __init__(self):
		self.dic = {}
		self.token = []
		return

	@classmethod
	def preprocess(self,document):
		"""
		なんやらかんやら正規表現する
		"""
		return document

	@classmethod
	def isHiragana(self,token):

		return True
	@classmethod
	def myappend(self,triplets,dic):

		return dic

	def fit(self,document):
		document = preprocess(document)
		document = [x for x in document]
		for elem in document:
			if isHiragana(elem):
				self.token(elem)
			else:
				if len(self.token) >= 3:
					token = maketriplet(self.token)
					dic = myappend(token,dic)
					token = []

	def triplets(self):

		return self.dic

