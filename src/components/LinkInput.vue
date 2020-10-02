<template>
  <section class="flex items-center p-6 sm:p-8 lg:p-10">
    <form
      class="md:flex w-full max-w-6xl md:mx-auto"
      autocomplete="off"
      @submit.prevent="handleSubmit"
    >
      <div class="md:flex-grow">
        <label for="link" class="sr-only">Link</label>
        <div class="relative rounded-md shadow-sm">
          <input
            id="link"
            class="form-input block w-full py-3 text-base leading-6 sm:leading-5"
            placeholder="Shorten your link"
            v-model="link"
          />
        </div>
      </div>
      <span class="block rounded-md shadow-sm mt-2 md:mt-0 md:ml-4 lg:ml-6">
        <button
          type="submit"
          class="inline-flex items-center justify-center w-full py-3 border border-transparent text-base leading-6 rounded-md text-white bg-indigo-600 hover:bg-indigo-500 focus:outline-none focus:border-indigo-700 focus:shadow-outline-indigo active:bg-indigo-700 transition ease-in-out duration-150"
          :disabled="loading"
        >
          <span
            v-if="loading"
            class="spin animate-spin h-7 w-7 border-4 border-indigo-400 rounded-full"
          />
          <span v-else class="tracking-wider">Shorten</span>
        </button>
      </span>
    </form>
  </section>
</template>

<script lang="ts">
import { defineComponent, ref, PropType } from "vue";

export default defineComponent({
  name: "LinkInput",
  props: { loading: Boolean },
  setup(props, ctx) {
    const link = ref("");

    return {
      link,
      handleSubmit() {
        ctx.emit("submit-link", link.value);
        link.value = "";
      }
    };
  }
});
</script>

<style scoped>
section {
  min-height: 11rem;
  background-color: #0d1836;
}

input,
button {
  height: 3.125rem;
  min-width: 10rem;
}
button:disabled {
  @apply bg-indigo-200;
  cursor: not-allowed;
}
.spin {
  border-top-color: #f0f5ff;
}
</style>
