export interface State {
  show: "input" | "result";
  loading: boolean;
  result?: {
    link: string;
    shortLink: string;
  };
  error?: string;
}

export interface Actions {
  reset(): void;
  submitLink(link: string): Promise<void>;
}
