import json

from rest_framework.renderers import JSONRenderer


class ProfileJSONRenderer(JSONRenderer):
    charset = "utf-8"

    def render(self, data, media_type=None, renderer_context=None):
        # If we receive a `token` key as part of the response, it will be a
        # byte object. Byte objects don't serialize well, so we need to
        # decode it before rendering the Profile object.
        # token = data["token"]

        # if token is not None and isinstance(token, bytes):
        #     # Also as mentioned above, we will decode `token` if it is of type
        #     # bytes.
        #     data["token"] = token.decode("utf-8")

        # Finally, we can render our data under the "profile" namespace.
        return json.dumps({"profile": data})
