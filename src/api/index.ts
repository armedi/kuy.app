const apiURL = process.env.VUE_APP_API_URL;

export const postLink = async (
  link: string
): Promise<{
  success: boolean;
  data?: { shortLink: string };
  message?: string;
}> => {
  return fetch(apiURL, {
    method: "POST",
    body: JSON.stringify({ link })
  }).then(response => response.json());
};
