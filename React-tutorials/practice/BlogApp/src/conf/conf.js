const conf = {
  appwriteUrl: String(import.meta.env.VITE_APPWRITE_URL),
  appwriteProjectId:
    String(import.meta.env.VITE_APPWRITE_PROJECT_ID) || "default-project-id",
  appwriteDatabaseId:
    String(import.meta.env.VITE_APPWRITE_DATABASE_ID) || "default-database-id",
  appwriteCollectionId:
    String(import.meta.env.VITE_APPWRITE_COLLECTION_ID) ||
    "default-collection-id",
  appwriteBucketId:
    String(import.meta.env.VITE_APPWRITE_BUCKET_ID) || "default-bucket-id",
  tinymceApiKey:
    String(import.meta.env.VITE_TINYMCE_APIKEY) || "default-api-key",
};

export default conf;
