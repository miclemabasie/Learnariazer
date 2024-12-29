import cv2
from texture import texture

def processing(image):
    """
    Convert and returns the given inputed image to grayscale
    """
    # Convert the image to BGR2GRAY color space
    gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    # Resize the image to 220 x 220 dimensions
    
    resized_image = cv2.resize(gray_image, (220, 220))

    # return image
    return resized_image

# load image 
path_to_image = "./database2.jpg"

# read the image using cv2
image = cv2.imread(path_to_image)

# Check if the image was successfully loaded
if image is None:
    print("There was an error loading the image from the given path.")
else:
    # Displaying the raw image to screen
    cv2.imshow("Raw Image", image)
    # proceed to processing the image
    processed_image = processing(image)

    textured_image = texture(image)


    cv2.imshow("Textured image", textured_image)

    # Display the processed image
    cv2.imshow("Processed Image", processed_image)
    cv2.waitKey(0)
    cv2.destroyAllWindows()