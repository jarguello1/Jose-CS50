# blurs an image

from PIL import Image, ImageFilter

#Blur Image
before = Image.open("stadium.bmp")
after = before.filter(ImageFilter.BoxBlur(1))
after.save("out.bmp")