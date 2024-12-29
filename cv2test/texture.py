import cv2
import numpy as np

def texture(image):
    # Apply a 2D convolution to the image
    kernel = np.array([[0, -1, 0], [-1, 4, -1], [0, -1, 0]])  # Example kernel for edge detection
    convolved_image = cv2.filter2D(image, -1, kernel)

    # Normalize the result
    normalized_image = cv2.normalize(convolved_image, None, alpha=0, beta=255, norm_type=cv2.NORM_MINMAX)

    # Apply a filter to the normalized result
    # applying median for blur filter
    filtered_image = cv2.medianBlur(normalized_image, 5)

    return filtered_image

