import { createApi, fetchBaseQuery } from "@reduxjs/toolkit/query/react";


const rapidApiKey = import.meta.env.VITE_RAAPID_API_ARTICLE_KEY

export const articleApi = createApi({
    reducerPath: "articleApi",
    baseQuery: fetchBaseQuery({
        baseUrl: "https://article-extractor-and-summarizer.p.rapidapi.com/",
        prepareHeaders: (headers) => {
            headers.set('X-RapidAPI-Key', "e77062eb91msh4dde1a91ecc4f2cp11902djsn277f35de9bd9");
            headers.set('X-RapidAPI-Host', 'article-extractor-and-summarizer.p.rapidapi.com');

            return headers;
        }
    }),
    endpoints: (builder) => ({
        getSummary: builder.query({
            query: (params) => `/summarize?url=${encodeURIComponent(params.articleUrl)}&length=3`
        })
    })
})


export const { useLazyGetSummaryQuery } = articleApi;